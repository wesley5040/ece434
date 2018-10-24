#!/usr/bin/env python3
# From: https://developers.google.com/sheets/api/quickstart/python
# Copyright 2018 Google LLC
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

# [START sheets_quickstart]
from __future__ import print_function
from googleapiclient.discovery import build
from httplib2 import Http
from oauth2client import file, client, tools
import time, sys, smbus

# If modifying these scopes, delete the file token.json.
SCOPES = 'https://www.googleapis.com/auth/spreadsheets'

# The ID and range of a sample spreadsheet.
SPREADSHEET_ID = '13Hi4m2UrfbVr5Bg12nZ23ZJg0PAR5GkY8vFZzVUqUa8'
RANGE_NAME = 'A2'

store = file.Storage('tokenPython.json')
creds = store.get()
if not creds or creds.invalid:
    flow = client.flow_from_clientsecrets('credentials.json', SCOPES)
    creds = tools.run_flow(flow, store)
service = build('sheets', 'v4', http=creds.authorize(Http()))


addr = 0x2a
bus  = smbus.SMBus(2)

com = [0x6A, 0x1, 0x1, 0xC, 0x0, 0x0, 0xA]

while True:
    bus.write_i2c_block_data(addr, 0x92, com)
    time.sleep(0.5)
    data = bus.read_i2c_block_data(addr, 0x55, 32)
    s0   = (65536 * data[0] + 256 * data[1] + data[2]) / 1000
    s1   = (65536 * data[3] + 256 * data[4] + data[5]) / 1000
    print("1: " + str(s0) + "A;  " + "2: " + str(s1) + "A")

    # Call the Sheets API
    # Compute a timestamp and pass the first two arguments
    values = [ [time.time()/60/60/24 + 25569 - 4/24, s0, s1]]
    body = { 'values': values }
    result = service.spreadsheets().values().append(spreadsheetId=SPREADSHEET_ID,
                            range=RANGE_NAME,
                            #  How the input data should be interpreted.
                            valueInputOption='USER_ENTERED',
                            # How the input data should be inserted.
                            # insertDataOption='INSERT_ROWS'
                            body=body
                            ).execute()

    updates = result.get('updates', [])
    print(updates)
