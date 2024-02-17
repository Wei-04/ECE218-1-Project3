/*! @mainpage Automatic Windshield Wiper Control System
* @date Wednesday, February 14, 2024
* @authors Harmon Cleary, Weiheng He
* @section genDesc General Description
*
* This is an implementation of a windshield wiper system to be used in a car.
* When the engine ignition is triggered, requiring the driver to be an occupant,
* then the engine light LED will turn on and the wiper system can be initiated.
* The driver will have the ability to select multiple different modes of the wiper
* system, being high (HI), low (LO), interval (INT), and OFF. HI would spin at 30
* rpm, LO would spin at 20 rpm, and INT will allow the driver to choose from
* three different intervals of a rotation every 3, 6, or 8 seconds. The last mode
* OFF would simply return the wipers to their resting position. In the case of an
* engine shutdown while the wipers are in use, they shall also go back to resting
* position with the sole exception of INT which shall remain stationary.
*
* @section changelog Changelog
* | Date | Description |
* |:----------:|:-----------------------------------------------|
* | 02/14/2024 | First version of program |

* 
*
*/


//=====[Libraries]=============================================================

#include "mbed.h" //library imports
#include "arm_book_lib.h"

#include "system.h" //our main module

//=====[Main function, the program entry point after power on or reset]========

int main()
{
    systemInit();
    while (true) {
        systemUpdate();
    }
}