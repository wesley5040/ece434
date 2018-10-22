#!/bin/bash
#
export PRUN=0
export TARGET=input1
echo PRUN=$PRUN
echo TARGET=$TARGET

config-pin P9_27 pruout
config-pin P9_25 pruin
config-pin -q P9_27
config-pin -q P9_25

