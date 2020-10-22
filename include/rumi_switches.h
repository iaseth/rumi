#ifndef RUMI_SWITCHES_H
#define RUMI_SWITCHES_H

#include "rumi_types.h"


void rumi_turn_off_debug (Rumi rumi);
void rumi_turn_on_debug  (Rumi rumi);

bool rumi_debug_is_off (Rumi rumi);
bool rumi_debug_is_on  (Rumi rumi);



#endif