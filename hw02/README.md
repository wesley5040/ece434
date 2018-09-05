# HW02
Wesley Van Pelt - CM3289

## Buttons and LEDs
1. Wire up your breadboard to have 4 buttons. Each is to have one terminal attached to +3.3V and the other to a GPIO port.
    * Done
2. Also wire up 4 LEDs with current limiting resistors. Tie the plus side of the LED to the GPIO port and run the minus to the resistor and to ground.
    * Done
3. Write a simple program that reads the switches and lights a corresponding LED. Use interrupts.
    * Run `./buttonLED.py` to check.

## Measuring a gpio pin on an Oscilloscope
<table>
    <thead>
        <tr><th>Question</th> <th>Shell (before)</th> <th>Shell (after)</th> <th>Python</th> <th>C</th></tr>
    </thead>
    <tbody>
        <tr><th>1. Min/Max voltage</th> <th>0.0/3.4</th> <th>0.0/3.4</th> <th>0.0/3.36</th> <th>Min/Max: x/x</th></tr>
        <tr><th>2. Period</th> <th>240ms</th> <th>216ms</th> <th>200ms</th> <th>Xms</th></tr>
        <tr><th>3. How close to 100ms</th> <th>+20ms</th> <th>+8ms</th> <th>+0ms</th> <th>x</th></tr>
        <tr><th>4. Why do they differ?</th> <th colspan=4>...</th></tr>
        <tr><th>5. htop processor usage</th> <th>20%</th> <th>11%</th> <th>3.5%</th> <th>x%</th></tr>
        <tr><th>6a. Shortest period (table below)</th> <th>Xms</th> <th>Xms</th> <th>Xms</th> <th>Xms</th></tr>
        <tr><th>6b. Shortest period proc usage</th> <th>Xms</th> <th>Xms</th> <th>Xms</th> <th>Xms</th></tr>
        <tr><th>7. How stable?</th> <th>+/-10ms</th> <th>+/-10ms</th> <th>+/-0ms</th> <th>...</th></tr>
        <tr><th>8. How stable when launching vim?</th> <th>Relatively</th> <th>Relatively</th> <th>More than bash</th> <th>...</th></tr>
    </tbody>
</table>
9. Try cleaning up togglegpio.sh and removing unneeded lines. Does it impact the period?
    * Yes, less than half the overhead time.
10. togglegpio uses bash (first line in file). Try using sh. Is the period shorter?
    * TODO
11. What's the shortest period you can get?
    * TODO

| Sleep (ms) | Sh0 Per (ms) | Sh0 Proc. (%) | Sh1 Per (ms) | Sh1 Proc. (%) | Py Per (ms) | Py Proc (%) | C Per (ms) | C Proc (%) |
| ---------- | ------------ | ------------- | ------------ | ------------- | ----------- | ----------- | ---------- | ---------- |
| 100        | x            | x             | x            | x             | x           | x           | x          | x          |
| 75         | x            | x             | x            | x             | x           | x           | x          | x          |
| 50         | x            | x             | x            | x             | x           | x           | x          | x          |
| 40         | x            | x             | x            | x             | x           | x           | x          | x          |
| 30         | x            | x             | x            | x             | x           | x           | x          | x          |
| 25         | x            | x             | x            | x             | x           | x           | x          | x          |
| 20         | x            | x             | x            | x             | x           | x           | x          | x          |
| 15         | x            | x             | x            | x             | x           | x           | x          | x          |
| 10         | x            | x             | x            | x             | x           | x           | x          | x          |
| 5          | x            | x             | x            | x             | x           | x           | x          | x          |
| 3          | x            | x             | x            | x             | x           | x           | x          | x          |
| 2          | x            | x             | x            | x             | x           | x           | x          | x          |
| 1          | x            | x             | x            | x             | x           | x           | x          | x          |
| 0.5        | x            | x             | x            | x             | x           | x           | x          | x          |
| 0          | x            | x             | x            | x             | x           | x           | x          | x          |

## Etch-a-sketch

## Other stuff
### `togglegpio.py`
TODO
