#include "rumi_switches.h"



#define RUMI_DEFINE_SWITCHES(x) \
	void rumi_turn_off_ ## x (Rumi rumi) { rumi->show_ ## x = false; } \
	void rumi_turn_on_  ## x (Rumi rumi) { rumi->show_ ## x = true; }

RUMI_DEFINE_SWITCHES(debug);
bool rumi_debug_is_off (Rumi rumi) { return !rumi->show_debug; }
bool rumi_debug_is_on  (Rumi rumi) { return rumi->show_debug; }


