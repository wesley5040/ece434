#!/usr/bin/env node
// Blinks various LEDs
const Blynk = require('blynk-library');
const b = require('bonescript');
const util = require('util');

const LED0 = 'P9_14';
b.pinMode(LED0, b.OUTPUT);

const AUTH = 'bec2d4a48e7b4defa105f6c707cc3f64';


var blynk = new Blynk.Blynk(AUTH);

var v0 = new blynk.VirtualPin(0);

v0.on('write', function(param) {
    console.log('V0:', param[0]);
    b.analogWrite(LED0, param[0]);
});

b.attachInterrupt(button, toggle, b.CHANGE);
