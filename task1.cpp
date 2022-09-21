#include <Arduino.h>
#include "task1.h"

String btn1Sta(uint8_t btn1State)
{
    if (btn1State == HIGH)
    {
        return "RELEASED";
    }
    else if (btn1State == LOW)
    {
        return "PUSHED";
    }
    else
        return "ERROR";
}
String btn2Sta(uint8_t btn2State)
{
    if (btn2State == HIGH)
    {
        return "RELEASED";
    }
    else if (btn2State == LOW)
    {
        return "PUSHED";
    }
    else
        return "ERROR";
}
String btn3Sta(uint8_t btn3State)
{
    if (btn3State == HIGH)
    {
        return "RELEASED";
    }
    else if (btn3State == LOW)
    {
        return "PUSHED";
    }
    else
        return "ERROR";
}

void task1()
{
    enum class TaskStates
    {
        INIT,
        WAIT_PRESS,
    };
    static TaskStates taskState = TaskStates::INIT;

    const uint8_t ONE_BTN_PIN = 13;
    const uint8_t TWO_BTN_PIN = 12;
    const uint8_t THREE_BTN_PIN = 33;
    static uint8_t ledGren = 25;
    static uint8_t ledBlue = 26;
    static uint8_t ledYellow = 27;

   

    switch (taskState)
    {
    case TaskStates::INIT:
    {
        Serial.begin(115200);

        Serial.begin(115200);
        pinMode(ONE_BTN_PIN, INPUT_PULLUP);
        pinMode(TWO_BTN_PIN, INPUT_PULLUP);
        pinMode(THREE_BTN_PIN, INPUT_PULLUP);
        pinMode(ledGren, OUTPUT);
        pinMode(ledBlue, OUTPUT);
        pinMode(ledYellow, OUTPUT);
        taskState = TaskStates::WAIT_PRESS;
        break;
    }
    case TaskStates::WAIT_PRESS:
    {

        if (Serial.available() > 0)
        {
            String command = Serial.readStringUntil('\n');

            if (command == "Led_1_OFF")
            {
                digitalWrite(ledGren, LOW);
            }
             if (command == "Led_1_ON")
            {
                digitalWrite(ledGren, HIGH);
            }
            if (command == "Led_2_OFF")
            {
                digitalWrite(ledBlue, LOW);
            }
            if (command == "Led_2_ON")
            {
                digitalWrite(ledBlue, HIGH);
            }
             if (command == "Led_3_OFF")
            {
                digitalWrite(ledYellow, LOW);
            }
              if (command == "Led_3_ON")
            {
                digitalWrite(ledYellow, HIGH);
            }

            else if (command == "readBUTTONS")
            {
                Serial.print("btn1: ");
                Serial.print(btn1Sta(digitalRead(ONE_BTN_PIN)).c_str());
                Serial.print(" ");
                Serial.print("btn2: ");
                Serial.print(btn2Sta(digitalRead(TWO_BTN_PIN)).c_str());
                Serial.print(" ");
                Serial.print("btn3: ");
                Serial.print(btn3Sta(digitalRead(THREE_BTN_PIN)).c_str());
                Serial.print('\n');
            }
        }
        break;
    }
    default:
    {
        break;
    }
    }
}