/*! @mainpage Ignition System Control
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
* 
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

void displayModeInit()
{
    void displayInit();
}

void displayMode()
{
    displayCharPositionWrite(0, 0);
    displayStringWrite("Mode:");
    displayCharPositionWrite(6, 0);
    displayStringWrite("replace"); //replace with function output from wiper system module
    displayCharPositionWrite(0, 1); 
    displayStringWrite("Interval:");
    displayCharPositionWrite(10, 1);
    displayStringWrite("replace");
}

//=====[Implementations of private functions]==================================
