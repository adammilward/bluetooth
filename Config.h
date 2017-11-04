/*
 * Config.h
 *
 *  Created on: 11 Mar 2017
 *      Author: Adam Milward
 */

#include "Arduino.h"

#ifndef CONFIG_H_
#define CONFIG_H_
class CONFIG {
public:
    static const int DELAY_MIN = 1;
    static const int DELAY_MAX = 256;
    /* Uno */                        //   ________
    static const byte RED_PIN = 2;   //  |   __   |
    static const byte GREEN_PIN = 3; //  |  /  \  |
    static const byte BLUE_PIN = 4;  //  | |    | |
    static const byte IREC_PIN = 12;  //  out  0  v+

    static const byte BT_RX = 12;
    static const byte BT_TX = 13;
    static const byte COMMAND_LENGTH = 4;


  /*static constexpr float A0_FACTOR = 0.026084756;
    static constexpr float A1_FACTOR = 0.014804804;
    static constexpr float A2_FACTOR = 0.014672619;
    static constexpr float A3_FACTOR = 0.014760479;
    static constexpr float A4_FACTOR = 0.014672619;
*/
    static constexpr float A0_FACTOR = 0.02583;
    static constexpr float A1_FACTOR = 0.01473;
    static constexpr float A2_FACTOR = 0.01461;
    static constexpr float A3_FACTOR = 0.01467;
    static constexpr float A4_FACTOR = 0.01460;

};
#endif /* CONFIG_H_ */
