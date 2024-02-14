/*! @mainpage Ignition System Control
* @date Wednesday, February 14, 2024
* @authors Harmon Cleary, Weiheng He
* @section genDesc General Description
*
* This module should be in charge of and control the ignition system of the car. This includes only allowing ignition
* when the driver is occupying his seat, and keeping the engine on even after the driver has left. Finally, the
* current state of the system will be represented by the blue LED on the Nucleo Board.
*
* @section changelog Changelog
* | Date | Description |
* |:----------:|:-----------------------------------------------|
* | 02/14/2024 | First version of ignition system |
* 
*
*/


//=====[Libraries]=============================================================

#include "mbed.h" //library imports
#include "arm_book_lib.h"

#include "ignition_system.h"
#include "display.h"

//=====[Declaration of private defines]========================================

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

//=====[Declarations (prototypes) of private functions]========================

//=====[Implementations of public functions]===================================

void systemInit()
{
    void ignitionInit();
    void displayInit();
}

void systemUpdate()
{
    bool engineUpdate();

    displayCharPositionWrite(0, 0);
    displayStringWrite("Mode:");
    displayCharPositionWrite(6, 0);
    displayStringWrite("replace"); //replace with function output from wiper system module
    displayCharPositionWrite(0, 1); //testing
    displayStringWrite("Interval:");
    displayCharPositionWrite(10, 1);
    displayStringWrite("replace");
}

//=====[Implementations of private functions]==================================
