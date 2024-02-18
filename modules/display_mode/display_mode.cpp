/*! @mainpage Display System Control
* @date Wednesday, February 14, 2024
* @authors Harmon Cleary, Weiheng He
* @section genDesc General Description
*
* This module is used to consolidate our display with the outputs and states of the wiper system.
*
* @section changelog Changelog
* | Date | Description |
* |:----------:|:-----------------------------------------------|
* | 02/14/2024 | First version of our display modes |
* | 02/15/2024 | Tried troubleshooting module, WIP |
* | 02/17/2024 | Changed display modules from ex 7.2 to 6.1 |
*
*/


//=====[Libraries]=============================================================

#include "mbed.h" //library imports
#include "arm_book_lib.h"

#include "wiper_system.h"
#include "display.h"

//=====[Declaration of private defines]========================================

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

//=====[Declarations (prototypes) of private functions]========================

//=====[Implementations of public functions]===================================

void displayModeInit() //initializes our display
{
    displayInit();
}

void displayMode() //this function updates our display with the current mode and interval
{
    displayCharPositionWrite(0, 0); //writing the mode
    displayStringWrite("Mode:");
    displayCharPositionWrite(5, 0);
    switch (getMode()) { //using cases to determine our mode
        case 0:
        displayStringWrite("LO  ");
        break;
        case 1:
        displayStringWrite("HI  ");
        break;
        case 2:
        displayStringWrite("INT ");
        break;
        case 3:
        displayStringWrite("OFF ");
        break;
    }

    displayCharPositionWrite(0, 1); //writing our interval
    displayStringWrite("Interval:");
    displayCharPositionWrite(9, 1);
    switch (getFreq()) { //using cases to determine our interval
        case 0:
        displayStringWrite("SHORT  ");
        break;
        case 1:
        displayStringWrite("MEDIUM ");
        break;
        case 2:
        displayStringWrite("LONG   ");
        break;
    }
}

//=====[Implementations of private functions]==================================
