#include <Arduino.h>
#line 1 "/home/pop-os/Trabajos/SisFisInt/Unidad_2/Evaluacion_2/sf1-unidad2-ev-2022-20-pikanisfi/App.ino"
#include "task1.h"
#include "task2.h"
#include "events.h"

buttonEvt_t buttonEvt = {false, BUTTONS::NONE};

#line 7 "/home/pop-os/Trabajos/SisFisInt/Unidad_2/Evaluacion_2/sf1-unidad2-ev-2022-20-pikanisfi/App.ino"
void setup();
#line 13 "/home/pop-os/Trabajos/SisFisInt/Unidad_2/Evaluacion_2/sf1-unidad2-ev-2022-20-pikanisfi/App.ino"
void loop();
#line 7 "/home/pop-os/Trabajos/SisFisInt/Unidad_2/Evaluacion_2/sf1-unidad2-ev-2022-20-pikanisfi/App.ino"
void setup()
{
    task1();
    task2();
}

void loop()
{
    task1();
    task2();
}
