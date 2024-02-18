Automatic Windshield Wiper Control System
Wednesday, February 14, 2024
Harmon Cleary, Weiheng He
Traver Cherrice
ECE 218-1

This is an implementation of a windshield wiper system to be used in a car.
When the engine ignition is triggered, requiring the driver to be an occupant,
then the engine light LED will turn on and the wiper system can be initiated.
The driver will have the ability to select multiple different modes of the wiper
system, being high (HI), low (LO), interval (INT), and OFF. HI would spin at 30
rpm, LO would spin at 20 rpm, and INT will allow the driver to choose from
three different intervals of a rotation every 3, 6, or 8 seconds. The last mode
OFF would simply return the wipers to their resting position. In the case of an
engine shutdown while the wipers are in use, they shall also go back to resting
position with the sole exception of INT which shall remain stationary.

Changelog
| Date | Description |
|:----------:|:-----------------------------------------------|
| 02/15/2024 | Wrote ReadMe |


Ignition System:
| Specification | Test Result | Comment |
| Ignition with Driver | Successful ignition | N/A |
| Ingition without driver | No ignition | N/A |
| Deignition | Successfully turned off engine | Cannot turn off engine with driver occupying seat |

Wiper System:
| LO | Motor spins slow | It's slower than expected |
| HI | Motor is slightly faster | N/A |
| INT 3 | Motor takes a long interval to spin | Its long |
| INT 6 | Motor takes an even longer interval to spin | Expected behavior based on last result |
| INT 8 | Motor takes longer interval than INT 6 | N/A |
