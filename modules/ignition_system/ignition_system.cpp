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

//=====[Defines]===============================================================

//=====[Declaration and initialization of public global objects]===============

DigitalIn driverOccupancy(D12); // Object associated driver seat contact
DigitalIn ignitionButton(D11); // Object associated with attempted ignition

DigitalOut ignitionLED(LED2); // Object associated with sucessful igntion

//=====[Declaration and initialization of public global variables]=============

//=====[Declarations (prototypes) of public functions]=========================

void ignitionInit(); //initializes inputs and outputs

bool engineUpdate(); //controls the engine state, returns the current engine state

//=====[Main function, the program entry point after power on or reset]========

//=====[Implementation of global functions]====================================

void ignitionInit() { //initializing inputs and outputs
    driverOccupancy.mode(PullDown);
    ignitionButton.mode(PullDown);
    
    ignitionLED = OFF;
}

bool engineUpdate() { //updates the engine states
    if (ignitionButton) {
        if (driverOccupancy) {
            ignitionLED = ON;
            return true; //we return true if the engine is on
        }
        else {
            ignitionLED = OFF;
            return false; //we return false if engine is off
        }
    }
    if (ignitionLED == ON) { //returning after ignition button is let go of
        return true;
    }
    else {
        return false;
    }
}