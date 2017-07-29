/*
 * AnaloguePin.h
 *
 *  Created on: 29 Jul 2017
 *      Author: Adam Milward
 */

#ifndef ANALOGUEPIN_H_
#define ANALOGUEPIN_H_



class AnaloguePin {
public:
    AnaloguePin();
    int pinNo;
    float factor;
    int anotherInt = 1;
    float read();
    void set(int inPin, float conversionFactor);

private:

};



#endif /* ANALOGUEPIN_H_ */
