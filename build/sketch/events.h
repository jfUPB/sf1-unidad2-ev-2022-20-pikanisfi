#line 1 "/home/pop-os/Trabajos/SisFisInt/Unidad_2/Evaluacion_2/sf1-unidad2-ev-2022-20-pikanisfi/events.h"
#ifndef _EVENTS_H_
#define _EVENTS_H_

enum class BUTTONS{NONE, ONE_BTN, TWO_BTN, THREE_BTN};

typedef struct{
    bool trigger;
    BUTTONS whichButton;
} buttonEvt_t;

extern buttonEvt_t buttonEvt;

#endif