DifferentialBot
===================================================================

## An arduino class to control differential robots

### Usage
To install the library simply copy it to the "sketchbook/libraries/" folder.
To use it include it in your sketch

```cpp
#include <DifferentialBot.h>

DifferentialBot myRobot(motL1,motL2,motR1,motR2,minSpeed,maxSpeed);
```
and call the function
```cpp
myRobot.drive(x,y);

```

The variables motL1, motL2, motR1 and motR2 are the pins each of the motors are connected to, while minSpeed and maxSpeed are the minimum and maximum pwm values to be able to start turning the motors and to limit the robot's speed, respectively.


The drive function has two operating modes which can be chosen with the last parameter, such as
```cpp
myRobot.drive(x,y);
myRobot.drive(x,y,1);
```
The difference is in the transition from "forward-(counter)clockwise" to "(counter)clockwise" to "backwards-(counter)clockwise".
In the first example, there is no direct "(counter)clockwise" rotation and the other transition along a curve, like a car would.This is the default behaviour.
In the second, the transition is done by maintaining its rotation sens. 
For example, where if the first command were to yield a "backwards-clockwise", the second one would output a "backwards-counterclockwise".