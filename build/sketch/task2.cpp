#line 1 "/home/pop-os/Trabajos/SisFisInt/Unidad_2/Evaluacion_2/sf1-unidad2-ev-2022-20-pikanisfi/task2.cpp"
#include <Arduino.h>
#include "task2.h"
#include "events.h"


void task2()
{
    enum class TaskState
    {
        INIT,
        WAIT_PRESS,
        WAIT_STABLE,
        WAIT_RELEASE
    };
    static TaskState taskState = TaskState::INIT;
    static uint8_t lastButtonPressed;
    static uint32_t initStableTime;

    const uint8_t ONE_BTN_PIN = 13;
    const uint8_t TWO_BTN_PIN = 12;
    const uint8_t THREE_BTN_PIN = 33;

    const uint32_t STABLE_TIME = 100;

    switch (taskState)
    {
    case TaskState::INIT:
    {
        pinMode(ONE_BTN_PIN, INPUT_PULLUP);
        pinMode(TWO_BTN_PIN, INPUT_PULLUP);
        pinMode(THREE_BTN_PIN, INPUT_PULLUP);

        taskState = TaskState::WAIT_PRESS;
        break;
    }
    case TaskState::WAIT_PRESS:
    {
        if (digitalRead(ONE_BTN_PIN) == LOW)
        {
            lastButtonPressed = ONE_BTN_PIN;
            initStableTime = millis();
            taskState = TaskState::WAIT_STABLE;
        }
        if (digitalRead(TWO_BTN_PIN) == LOW)
        {
            lastButtonPressed = TWO_BTN_PIN;
            initStableTime = millis();
            taskState = TaskState::WAIT_STABLE;
        }
        if (digitalRead(THREE_BTN_PIN) == LOW)
        {
            lastButtonPressed = THREE_BTN_PIN;
            initStableTime = millis();
            taskState = TaskState::WAIT_STABLE;
        }
        break;
    }
    case TaskState::WAIT_STABLE:
    {
        if (digitalRead(lastButtonPressed) != LOW)
        {
            taskState = TaskState::WAIT_PRESS;
        }
        else if ((millis() - initStableTime) > STABLE_TIME)
        {
            if (lastButtonPressed == ONE_BTN_PIN)
                buttonEvt.whichButton = BUTTONS::ONE_BTN;
            else if (lastButtonPressed == TWO_BTN_PIN)
                buttonEvt.whichButton = BUTTONS::TWO_BTN;
            else if (lastButtonPressed == THREE_BTN_PIN)
                buttonEvt.whichButton = BUTTONS::THREE_BTN;
            buttonEvt.trigger = true;
            // printf("Button pressed: %d\n", lastButtonPressed);
            taskState = TaskState::WAIT_RELEASE;
        }
        break;
    }
    case TaskState::WAIT_RELEASE:
    {
        if (digitalRead(lastButtonPressed) == HIGH)
        {
            taskState = TaskState::WAIT_PRESS;
        }
        break;
    }

    default:
    {
    }
    }
}