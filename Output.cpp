/*
 * Output.cpp
 *
 *  Created on: 21 Aug 2017
 *      Author: Adam Milward
 */

#include "Output.h"
#include "Arduino.h"



Output::Output(int inID) {
    ID = inID;
    //name = inName;
    Serial.println("ID is ");
    Serial.println(ID);
}

