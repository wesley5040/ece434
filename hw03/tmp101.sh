#!/bin/bash

T1=$(echo "$(( `i2cget -y $1 $2 00` )) * 1.8 + 32" | bc)
T2=$(echo "$(( `i2cget -y $1 $3 00` )) * 1.8 + 32" | bc)

echo Temp 1:  $T1 F
echo Temp 2:  $T2 F
