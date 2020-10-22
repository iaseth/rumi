#ifndef RUMI_SWITCHES_H
#define RUMI_SWITCHES_H

#include "rumi_types.h"

#define RUMI_DECLARE_SWITCHES(x) \
	void rumi_turn_off_ ## x (Rumi rumi); \
	void rumi_turn_on_  ## x (Rumi rumi);

#define RUMI_DECLARE_INDICATORS(x) \
	bool rumi_ ## x ## _is_off (Rumi rumi); \
	bool rumi_ ## x ## _is_on  (Rumi rumi);

RUMI_DECLARE_SWITCHES(debug);
RUMI_DECLARE_INDICATORS(debug);



#endif