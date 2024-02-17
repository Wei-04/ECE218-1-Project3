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
