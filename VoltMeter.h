/*
 * VoltMeter.h
 *
 *  Created on: 29 Jul 2017
 *      Author: Adam Milward
 */

#include "AnaloguePin.h"

#ifndef VOLTMETER_H_
#define VOLTMETER_H_



class VoltMeter {
public:
    VoltMeter();
    void serialOutAll();
    AnaloguePin APin0;
    AnaloguePin APin1;
    AnaloguePin APin2;
    AnaloguePin APin3;
    AnaloguePin APin4;
    AnaloguePin APin5;
};



#endif /* VOLTMETER_H_ */
