/*! @mainpage Overall System Control
* @date Wednesday, February 14, 2024
* @authors Harmon Cleary, Weiheng He
* @section genDesc General Description
*
* This module will envoke all the other modules in order to make a fully working embedded system. This
* will be the module called upon in our main.
*
* @section changelog Changelog
* | Date | Description |
* |:----------:|:-----------------------------------------------|
* | 02/14/2024 | First version of system |
* | 02/15/2024 | Added display module |
* | 02/17/2024 | Added wiper module |
*
*/


//=====[Libraries]=============================================================

#include "mbed.h" //library imports
#include "arm_book_lib.h"

#include "ignition_system.h"
#include "display_mode.h"
#include "wiper_system.h"

//=====[Declaration of private defines]========================================

#define SYSTEM_TIME_INCREMENT_MS   10

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

//=====[Declarations (prototypes) of private functions]========================

//=====[Implementations of public functions]===================================

void systemInit() //our initializations
{
    ignitionInit();
    displayModeInit();
}

void systemUpdate() //our update functions which will loop
{
    engineUpdate(); //updates engine state
    displayMode(); //updates our display on the current wiper mode and interval
    updateWiperSystem(); //controls the wipers

    delay(SYSTEM_TIME_INCREMENT_MS);
}

//=====[Implementations of private functions]==================================
