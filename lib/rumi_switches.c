#include "rumi_switches.h"

void rumi_turn_off_debug (Rumi rumi) { rumi->show_debug = false; }
void rumi_turn_on_debug  (Rumi rumi) { rumi->show_debug = true; }

bool rumi_debug_is_off (Rumi rumi) { return !rumi->show_debug; }
bool rumi_debug_is_on  (Rumi rumi) { return rumi->show_debug; }


