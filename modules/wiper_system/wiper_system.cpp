/*! @mainpage Windshield Wiper System Control
* @date Wednesday, February 14, 2024
* @authors Harmon Cleary, Weiheng He
* @section genDesc General Description
*
* This module should hold control of our windshield wipers on the car. There will be multiple modes of control along with
* an interval selector. The possible modes include high (HI), low (LO), interval (INT), and OFF. Modes HI and LO will
* spin at 40 and 30 rpm respectively while the INT mode will spin according to the selected interval, being every 3, 6, or 8
* seconds.
*
* @section changelog Changelog
* | Date | Description |
* |:----------:|:-----------------------------------------------|
* | 02/14/2024 | First version of the wiper system |
* 
*
*/


//=====[Libraries]=============================================================

#include "mbed.h" //library imports
#include "arm_book_lib.h"

//=====[Defines]===============================================================

#define MD_TH1  0.25
#define MD_TH2  0.50
#define MD_TH3  0.75
#define MD_HYST 0.05

#define FD_TH1  0.333
#define FD_TH2  0.667
#define FD_HYST 0.05

//=====[Declaration and initialization of public global objects]===============

AnalogIn mode_dial(A1);
AnalogIn freq_dial(A0);
static int md_state = 0;
static int fd_state = 0;

//=====[Declaration and initialization of public global variables]=============

//=====[Declarations (prototypes) of public functions]=========================

void updatePotReading();

//=====[Implementation of global functions]====================================

void updatePotReading() {
    float md_r = mode_dial.read();
    switch (md_state) {
        case 0:
            if (md_r > MD_TH1 + MD_HYST) md_state = 1;  
            break;
        case 1:
            if (md_r > MD_TH2 + MD_HYST) md_state = 2;
            if (md_r < MD_TH1 - MD_HYST) md_state = 0;
            break;
        case 2:
            if (md_r > MD_TH3 + MD_HYST) md_state = 3;
            if (md_r < MD_TH2 - MD_HYST) md_state = 1;
            break;
        case 3:
            if (md_r < MD_TH3 - MD_HYST) md_state = 2;
            break;
    }
    if (md_state != 2) return;
    float fd_r = mode_dial.read();
    switch (fd_state) {
        case 0:
            if (fd_r > FD_TH1 + FD_HYST) md_state = 1;  
            break;
        case 1:
            if (fd_r > FD_TH2 + FD_HYST) md_state = 2;
            if (fd_r < FD_TH1 - FD_HYST) md_state = 0;
            break;
        case 2:
            if (fd_r < MD_TH3 - MD_HYST) md_state = 2;
            break;
    }

};