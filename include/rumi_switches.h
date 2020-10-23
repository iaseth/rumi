#ifndef RUMI_SWITCHES_H
#define RUMI_SWITCHES_H

#include "rumi_types.h"
#include "ru.h"

#define RUMI_DECLARE_SWITCHES(x) \
	const struct RumiRuStruct*  rumi_turn_off_ ## x (Rumi rumi); \
	const struct RumiRuStruct*  rumi_turn_on_  ## x (Rumi rumi);

#define RUMI_DECLARE_INDICATORS(x) \
	bool rumi_ ## x ## _is_off (Rumi rumi); \
	bool rumi_ ## x ## _is_on  (Rumi rumi);

#define RUMI_DECLARE_INDICATORS_PLURAL(x) \
	bool rumi_ ## x ## _are_off (Rumi rumi); \
	bool rumi_ ## x ## _are_on  (Rumi rumi);

#define RUMI_DECLARE_SWITCHES_AND_INDICATORS(x) \
	RUMI_DECLARE_SWITCHES(x) \
	RUMI_DECLARE_INDICATORS(x)

#define RUMI_DECLARE_SWITCHES_AND_INDICATORS_PLURAL(x) \
	RUMI_DECLARE_SWITCHES(x) \
	RUMI_DECLARE_INDICATORS_PLURAL(x)

RUMI_DECLARE_SWITCHES_AND_INDICATORS(debug);
RUMI_DECLARE_SWITCHES_AND_INDICATORS_PLURAL(warnings);
RUMI_DECLARE_SWITCHES_AND_INDICATORS_PLURAL(suggestions);

RUMI_DECLARE_SWITCHES_AND_INDICATORS(color);
RUMI_DECLARE_SWITCHES_AND_INDICATORS(date);
RUMI_DECLARE_SWITCHES_AND_INDICATORS(time);
RUMI_DECLARE_SWITCHES_AND_INDICATORS(instant);



#undef RUMI_DECLARE_SWITCHES_AND_INDICATORS_PLURAL
#undef RUMI_DECLARE_SWITCHES_AND_INDICATORS
#undef RUMI_DECLARE_INDICATORS_PLURAL
#undef RUMI_DECLARE_INDICATORS
#undef RUMI_DECLARE_SWITCHES



#endif