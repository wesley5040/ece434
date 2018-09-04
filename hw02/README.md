# HW02
Wesley Van Pelt - CM3289

## Buttons and LEDs
1. Wire up your breadboard to have 4 buttons. Each is to have one terminal attached to +3.3V and the other to a GPIO port.
    * #TODO
2. Also wire up 4 LEDs with current limiting resistors. Tie the plus side of the LED to the GPIO port and run the minus to the resistor and to ground.
    * #TODO
3. Write a simple program that reads the switches and lights a corresponding LED. Use interrupts.
    * #TODO

## Measuring a gpio pin on an Oscilloscope
<table>
    <thead>
        <tr><th>Question</th> <th>Shell (before)</th> <th>Shell (after)</th> <th>Python</th> <th>C</th></tr>
    </thead>
    <tbody>
        <tr><th>1. Min and max voltage</th> <th>Min/Max: x/x</th> <th>Min/Max: x/x</th> <th>Min/Max: x/x</th> <th>Min/Max: x/x</th></tr>
        <tr><th>2. Period</th> <th>Xms</th> <th>Xms</th> <th>Xms</th> <th>Xms</th></tr>
        <tr><th>3. How close to 100ms</th> <th>x</th> <th>x</th> <th>x</th> <th>x</th></tr>
        <tr><th>4. Why do they differ?</th> <th colspan=4>...</th></tr>
        <tr><th>5. htop processor usage</th> <th>x%</th> <th>x%</th> <th>x%</th> <th>x%</th></tr>
        <tr><th>6a. Shortest period (table below)</th> <th>Xms</th> <th>Xms</th> <th>Xms</th> <th>Xms</th></tr>
        <tr><th>6b. Shortest period proc usage</th> <th>Xms</th> <th>Xms</th> <th>Xms</th> <th>Xms</th></tr>
        <tr><th>7. How stable?</th> <th>...</th> <th>...</th> <th>...</th> <th>...</th></tr>
        <tr><th>8. How stable when launching emacs?</th> <th>...</th> <th>...</th> <th>...</th> <th>...</th></tr>
    </tbody>
</table>
9. Try cleaning up togglegpio.sh and removing unneeded lines. Does it impact the period?
    * ...
10. togglegpio uses bash (first line in file). Try using sh. Is the period shorter?
    * ...
11. What's the shortest period you can get?
    * ...

| Sleep (ms) | Sh0 Per (ms) | Sh0 Proc. (%) | Sh1 Per (ms) | Sh1 Proc. (%) | Py Per (ms) | Py Proc (%) | C Per (ms) | C Proc (%) |
| ---------- | ------------ | ------------- | ------------ | ------------- | ----------- | ----------- | ---------- | ---------- |
| 100        | x            | x             | x            | x             | x           | x           | x          | x          |
| 50         | x            | x             | x            | x             | x           | x           | x          | x          |
| xx         | x            | x             | x            | x             | x           | x           | x          | x          |

## Etch-a-sketch
