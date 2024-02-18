/*! @mainpage Windshield Wiper System Control
* @date Wednesday, February 14, 2024
* @authors Harmon Cleary, Weiheng He
* @section genDesc General Description
*
* This module should hold control of our windshield wipers on the car. There will be multiple modes of control along with
* an interval selector. The possible modes include HI, LO, INT, and OFF. Modes HI and LO will
* spin at 40 and 30 rpm respectively while the INT mode will spin according to the selected interval, being every 3, 6, or 8
* seconds.
*
* @section changelog Changelog
* | Date | Description |
* |:----------:|:-----------------------------------------------|
* | 02/14/2024 | First version of the wiper system |
* | 02/14/2024 | Final version of the wiper system |
*
*/


//=====[Libraries]=============================================================

#include "mbed.h" //library imports
#include "arm_book_lib.h"
#include "system.h"
#include "ignition_system.h"

//=====[Defines]===============================================================

#define MD_TH1  0.25 //LO
#define MD_TH2  0.50 //HI
#define MD_TH3  0.75 //INT
#define MD_HYST 0.05 //OFF

#define FD_TH1  0.333 //SHORT
#define FD_TH2  0.667 //MEDIUM
#define FD_HYST 0.05 //LONG

#define PWM_MIN 0.05
#define PWM_MAX 0.09
#define ANGLE_MAX 67.0

#define DPS_LO 120.0
#define DPS_HI 180.0

#define W_INC_LO (PWM_MAX - PWM_MIN) / (ANGLE_MAX / DPS_LO) * .04
#define W_INC_HI (PWM_MAX - PWM_MIN) / (ANGLE_MAX / DPS_HI) * .04


//=====[Declaration and initialization of public global objects]===============

AnalogIn mode_dial(A1);
AnalogIn freq_dial(A0);

PwmOut servo(PE_8);

static int md_state = 0;
static int fd_state = 0;
static int acc_time_ms = 0;

typedef enum wiperState {
    W_STOP,
    W_RISE,
    W_FALL
} wiperState_t;

static wiperState_t w_state = W_STOP;

//=====[Declaration and initialization of public global variables]=============

//=====[Declarations (prototypes) of public functions]=========================

static void updatePotReading();

void initWiperSystem();
void updateWiperSystem();
int getMode();
int getFreq();

//=====[Implementation of global functions]====================================

void initWiperSystem() {
    servo.write(PWM_MIN);
    servo.period(.02);
}

static void updatePotReading() { //LO HI INT OFF, 0 1 2 3

    float md_r = mode_dial.read();
    if ((md_state == 0) && (md_r > MD_TH1 + MD_HYST)) {
        md_state = 1;
    }  
    if ((md_state == 1) && (md_r > MD_TH2 + MD_HYST)) {
        acc_time_ms = 0;
        md_state = 2;
    }
    if ((md_state == 1) && (md_r < MD_TH1 - MD_HYST)) {
        md_state = 0;
    }
    if ((md_state == 2) && (md_r > MD_TH3 + MD_HYST)) {
        md_state = 3;
    }
    if ((md_state == 2) && (md_r < MD_TH2 - MD_HYST)) {
        md_state = 1;
    }
    if ((md_state == 3) && (md_r < MD_TH3 - MD_HYST)) {
        acc_time_ms = 0;
        md_state = 2;
    }

    float fd_r = freq_dial.read(); //0 1 2, short med long

    if ((fd_state == 0) && (fd_r > FD_TH1 + FD_HYST)) {
        acc_time_ms = 0;
        fd_state = 1;
    }  
    if ((fd_state == 1) && (fd_r > FD_TH2 + FD_HYST)) {
        acc_time_ms = 0;
        fd_state = 2;
    }
    if ((fd_state == 1) && (fd_r < FD_TH1 - FD_HYST)) {
        acc_time_ms = 0;
        fd_state = 0;
    }
    if ((fd_state == 2) && (fd_r < FD_TH2 - FD_HYST)) {
        acc_time_ms = 0;
        fd_state = 1;
    }
}

void updateWiperSystem() {
    if (!engineUpdate()) {
        if (md_state != 2) {
            servo.write(PWM_MIN);
        }
        return;
    }
    updatePotReading();
    if (md_state == 0) {
        if (w_state == W_RISE) {
            servo.write(servo + W_INC_LO);
            if (servo > PWM_MAX) {
                w_state = W_FALL;
            }
        }
        else {
            servo.write(servo - W_INC_LO);
            if (servo < PWM_MIN) {
                w_state = W_RISE;
            }
        }
    }
    if (md_state == 1) {
        if (w_state == W_RISE) {
            servo.write(servo + W_INC_HI);
            if (servo > PWM_MAX) {
                w_state = W_FALL;
            }
        }
        else {
            servo.write(servo - W_INC_HI);
            if (servo < PWM_MIN) {
                w_state = W_RISE;
            }
        }
    }
    if (md_state == 2) {
        if (w_state == W_RISE) {
            servo.write(servo + W_INC_LO);
            if (servo > PWM_MAX) {
                w_state = W_FALL;
            }
        }
        else if(w_state == W_FALL) {
            servo.write(servo - W_INC_LO);
            if (servo < PWM_MIN) {
                w_state = W_STOP;
                acc_time_ms = 0;
            }
        } 
        else {
            acc_time_ms += 10;
            if (fd_state == 0 && acc_time_ms >= 375) {
                w_state = W_RISE;
            }
            if (fd_state == 1 && acc_time_ms >= 750) {
                w_state = W_RISE;
            }
            if (fd_state == 2 && acc_time_ms >= 1000) {
                w_state = W_RISE;
            }
        }      
    }
    if (md_state == 3) {
        if (servo > PWM_MIN) {
            servo.write(PWM_MIN);
        }
    }
}

int getMode() {
    return md_state;
}
int getFreq() {
    return fd_state;
}