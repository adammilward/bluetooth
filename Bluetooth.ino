// Basic Bluetooth sketch HC-06_01
// Connect the Hc-06 module and communicate using the serial monitor
//
// The HC-06 defaults to AT mode when first powered on.
// The default baud rate is 9600
// The Hc-06 requires all AT commands to be in uppercase. NL+CR should not be added to the command string
//

#include <Arduino.h>
#include <SoftwareSerial.h>
#include "Config.h"
#include "VoltMeter.h"

SoftwareSerial BTserial(CONFIG::BT_RX, CONFIG::BT_TX); // RX | TX
// Connect the HC-05 TX to the Arduino RX on pin 12.
// Connect the HC-05 RX to the Arduino TX on pin 3 through a voltage divider.
VoltMeter Meter;

unsigned long waitMillis = millis() + 1000;
int delayTime = 1;
int count = 0;

void setup()
{
    Serial.begin(9600);
    Serial.println("Enter AT commands:");

    // HC-05 default serial speed is 9600
    BTserial.begin(9600);
    BTserial.write("ready to receive");
}

void loop()
{

    if ((long) (millis() - waitMillis) >= 0) {
        count++;
        if (count >100) {
            count = 0;
            delayTime *= 10;
            Serial.println(0);
        }
        waitMillis = millis() + delayTime;
        Meter.serialOutAll();
    }
    //Meter.serialOutAll();
    // Keep reading from HC-06 and send to Arduino Serial Monitor
    if (BTserial.available())
    {
        Serial.write("we have bluetoth reeption");
        Serial.write(BTserial.read());
    }

    // Keep reading from Arduino Serial Monitor and send to HC-06
    if (Serial.available())
    {
        BTserial.write(Serial.read());
    }

}
