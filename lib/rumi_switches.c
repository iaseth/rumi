#include "rumi_switches.h"



#define RUMI_DEFINE_SWITCHES(x) \
	void rumi_turn_off_ ## x (Rumi rumi) { rumi->show_ ## x = false; } \
	void rumi_turn_on_  ## x (Rumi rumi) { rumi->show_ ## x = true; }

#define RUMI_DEFINE_INDICATORS(x) \
	bool rumi_ ## x ## _is_off (Rumi rumi) { return !rumi->show_ ## x; } \
	bool rumi_ ## x ## _is_on  (Rumi rumi) { return  rumi->show_ ## x; }

RUMI_DEFINE_SWITCHES(debug);
RUMI_DEFINE_INDICATORS(debug);


