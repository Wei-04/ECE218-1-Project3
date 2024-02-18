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

void systemInit()
{
    ignitionInit();
    displayModeInit();
<<<<<<< HEAD

=======
>>>>>>> cbfd3cca8615d5935ab0026a8e7c93de78ad13ed
}

void systemUpdate()
{
    engineUpdate();
    displayMode();
    updateWiperSystem();
    delay(10);
}

//=====[Implementations of private functions]==================================
