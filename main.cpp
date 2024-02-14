/*! @mainpage Automatic Windshield Wiper Control System
* @date Wednesday, February 14, 2024
* @authors Harmon Cleary, Weiheng He
* @section genDesc General Description
*
* This is an implementation of a windshield wiper system to be used in a car.
* The driver will have the ability to select multiple modes of wipers (elaborate later).
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

//=====[Main function, the program entry point after power on or reset]========

int main()
{
    void systemInit();
    while (true) {
        void systemUpdate();
    }
}