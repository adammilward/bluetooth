/*
 * VoltMeter.cpp
 *
 *  Created on: 29 Jul 2017
 *      Author: Adam Milward
 */

#include "VoltMeter.h"
#include "Config.h"
#include "Arduino.h"
#include "AnaloguePin.h"



VoltMeter::VoltMeter() {

    APin0.set(A0, CONFIG::A0_FACTOR);
    APin1.set(A1, CONFIG::A1_FACTOR);
    APin2.set(A2, CONFIG::A2_FACTOR);
    APin3.set(A3, CONFIG::A3_FACTOR);
    APin4.set(A4, CONFIG::A4_FACTOR);
}

void VoltMeter::serialOutAll() {
    //Serial.println(APin0.read());
    Serial.print(APin0.read());
    Serial.print("V     ");
    Serial.print(APin1.read());
    Serial.print("V     ");
    //Serial.print(APin2.read());
    //Serial.print("V     ");
    //Serial.print(APin3.read());
    //Serial.print("V     ");
    //Serial.print(APin4.read());
    //Serial.print("V     ");
    //Serial.print((APin0.read()-APin1.read()));
    Serial.print((APin0.read()-APin1.read()));
    Serial.print("V    ");
    //Serial.print("uA    ");
    //Serial.print((APin1.read()-APin2.read())/1000);
    //Serial.print("uA    ");
    Serial.println("");
}


