#line 1 "/home/pop-os/Trabajos/SisFisInt/Unidad_2/Evaluacion_2/sf1-unidad2-ev-2022-20-pikanisfi/task1.cpp"
#include <Arduino.h>
#include "task1.h"
#include "events.h"

String btnState(uint8_t btn1State, uint8_t btn2State, uint8_t btn3State)
{
    if (btn1State == HIGH)
    {
        return "RELEASED";
    }
    else if (btn1State == LOW)
    {
        return "PUSHED";
    }
    if (btn2State == HIGH)
    {
        return "RELEASED";
    }
    else if (btn2State == LOW)
    {
        return "PUSHED";
    }
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
String ledSelected(uint8_t ledGren,uint8_t ledBlue, uint8_t ledYellow)
{
    if (ledGren == HIGH)
    {
        return "1";
    }
    else if (ledBlue == HIGH)
    {
        return "2";
    }
    else if (ledYellow == HIGH)
    {
        return "3";
    }
    else
    return "ERROR";
}
String ledStatus(uint8_t ledGren,uint8_t ledBlue, uint8_t ledYellow)
{
   if (ledGren == LOW)
    {
        return "ON";
    }
    else if (ledGren == HIGH)
    {
        return "OFF";
    }
    else if (ledBlue == LOW)
    {
        return "ON";
    }
    else if (ledBlue == HIGH)
    {
        return "OFF";
    }
    else if (ledYellow == LOW)
    {
        return "ON";
    }
    else if (ledYellow == HIGH)
    {
        return "OFF";
    }
    else
    return "ERROR";
}


void task1()
{

    enum class TaskStates
    {
        INIT,
        WAIT_TIMEOUT,
    };
    static TaskStates taskState = TaskStates::INIT;

    static uint8_t ledGren = 25;
    static uint8_t ledBlue = 26;
    static uint8_t ledYellow = 27;

    static bool ledStatus = false;

    static bool if_off_btn_one = false;
    static bool if_off_btn_two = false;
    static bool if_off_btn_three = false;

    switch (taskState)
    {
    case TaskStates::INIT:
    {
        Serial.begin(115200);

        ledStatus = LOW;
        pinMode(ledGren, OUTPUT);
        digitalWrite(ledGren, ledStatus);
        pinMode(ledBlue, OUTPUT);
        digitalWrite(ledBlue, ledStatus);
        pinMode(ledYellow, OUTPUT);
        digitalWrite(ledYellow, ledStatus);

        taskState = TaskStates::WAIT_TIMEOUT;
        break;
    }
    case TaskStates::WAIT_TIMEOUT:
    {
        if (buttonEvt.trigger == true)
        {
            buttonEvt.trigger = false;
            if (buttonEvt.whichButton == BUTTONS::ONE_BTN)
            {
                if (if_off_btn_one == false)
                {
                    ledStatus = HIGH;
                    pinMode(ledGren, OUTPUT);
                    digitalWrite(ledGren, ledStatus);
                    if_off_btn_one = true;
                }
                else if (if_off_btn_one == true)
                {
                    ledStatus = LOW;
                    pinMode(ledGren, OUTPUT);
                    digitalWrite(ledGren, ledStatus);
                    if_off_btn_one = false;
                }
            }
            else if (buttonEvt.whichButton == BUTTONS::TWO_BTN)
            {
                if (if_off_btn_two == false)
                {
                    ledStatus = HIGH;
                    pinMode(ledBlue, OUTPUT);
                    digitalWrite(ledBlue, ledStatus);
                    if_off_btn_two = true;
                }
                else if (if_off_btn_two == true)
                {
                    ledStatus = LOW;
                    pinMode(ledBlue, OUTPUT);
                    digitalWrite(ledBlue, ledStatus);
                    if_off_btn_two = false;
                }
            }
            else if (buttonEvt.whichButton == BUTTONS::THREE_BTN)
            {
                if (if_off_btn_three == false)
                {
                    ledStatus = HIGH;
                    pinMode(ledYellow, OUTPUT);
                    digitalWrite(ledYellow, ledStatus);
                    if_off_btn_three = true;
                }
                else if (if_off_btn_three == true)
                {
                    ledStatus = LOW;
                    pinMode(ledYellow, OUTPUT);
                    digitalWrite(ledYellow, ledStatus);
                    if_off_btn_three = false;
                }
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