#!/bin/bash
#
export PRUN=0
export TARGET=sine1
echo PRUN=$PRUN
echo TARGET=$TARGET

config-pin P9_27 pruout
config-pin -q P9_27
