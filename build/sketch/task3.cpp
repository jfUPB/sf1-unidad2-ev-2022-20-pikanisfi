#line 1 "/home/pop-os/Trabajos/SisFisInt/Unidad_2/Evaluacion_2/sf1-unidad2-ev-2022-20-pikanisfi/task3.cpp"
#include <Arduino.h>
#include "task3.h"
#include "events.h"

String btn1State(uint8_t btn1State)
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
String btn2State(uint8_t btn2State)
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
String btn3State(uint8_t btn3State)
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
String ledSelector(uint8_t ledGren, uint8_t ledBlue, uint8_t ledYellow)
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
String ledSta(uint8_t ledGren, uint8_t ledBlue, uint8_t ledYellow)
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

void task2()
{
    if (Serial.available() > 0)
    {
        String command = Serial.readStringUntil('\n');
        if (command == "ledCont")
        {
            Serial.print("led: ");
            Serial.print(ledSelector(digitalRead(ledBlue), digitalRead(ledGren), digitalRead(ledYellow)).c_str());
            Serial.print("                ");
            Serial.print("led: ");
            Serial.print(ledSta(digitalRead(ledBlue), digitalRead(ledGren), digitalRead(ledYellow)).c_str());
            Serial.print('\n');
        }
        else if (command == "readBUTTONS")
        {
            Serial.print("btn1: ");
            Serial.print(btn1State(digitalRead(ONE_BTN_PIN)).c_str());
            Serial.print("btn2: ");
            Serial.print(btn2State(digitalRead(TWO_BTN_PIN)).c_str());
            Serial.print("btn3: ");
            Serial.print(btn3State(digitalRead(THREE_BTN_PIN)).c_str());
            Serial.print('\n');
        }
    }
}
