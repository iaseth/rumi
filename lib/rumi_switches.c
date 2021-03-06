#include "rumi_switches.h"

#include <stdlib.h>

#define RUMI_DEFINE_SWITCHES(x) \
	const struct RumiRuStruct*  rumi_turn_off_ ## x (Rumi rumi) {     \
		if (rumi == NULL || rumi->parent != NULL) return ru;          \
		rumi->show_ ## x = false;                                     \
		return ru;                                                    \
	}                                                                 \
	const struct RumiRuStruct*  rumi_turn_on_  ## x (Rumi rumi) {     \
		if (rumi == NULL || rumi->parent != NULL) return ru;          \
		rumi->show_ ## x =  true;                                     \
		return ru;                                                    \
	}

#define RUMI_DEFINE_INDICATORS(x)                                     \
	bool rumi_ ## x ## _is_off (Rumi rumi) {                          \
		if (rumi == NULL) return false;                               \
		return !rumi->show_ ## x;                                     \
	}                                                                 \
	bool rumi_ ## x ## _is_on  (Rumi rumi) {                          \
		if (rumi == NULL) return false;                               \
		return  rumi->show_ ## x;                                     \
	}

#define RUMI_DEFINE_INDICATORS_PLURAL(x)                              \
	bool rumi_ ## x ## _are_off (Rumi rumi) {                         \
		if (rumi == NULL) return false;                               \
		return !rumi->show_ ## x;                                     \
	}                                                                 \
	bool rumi_ ## x ## _are_on  (Rumi rumi) {                         \
		if (rumi == NULL) return false;                               \
		return  rumi->show_ ## x;                                     \
	}

#define RUMI_DEFINE_SWITCHES_AND_INDICATORS(x) \
	RUMI_DEFINE_SWITCHES(x) \
	RUMI_DEFINE_INDICATORS(x)

#define RUMI_DEFINE_SWITCHES_AND_INDICATORS_PLURAL(x) \
	RUMI_DEFINE_SWITCHES(x) \
	RUMI_DEFINE_INDICATORS_PLURAL(x)


RUMI_DEFINE_SWITCHES_AND_INDICATORS(debug);

RUMI_DEFINE_SWITCHES_AND_INDICATORS_PLURAL(warnings);
RUMI_DEFINE_SWITCHES_AND_INDICATORS_PLURAL(suggestions);

RUMI_DEFINE_SWITCHES_AND_INDICATORS(color);
RUMI_DEFINE_SWITCHES_AND_INDICATORS(date);
RUMI_DEFINE_SWITCHES_AND_INDICATORS(time);
RUMI_DEFINE_SWITCHES_AND_INDICATORS(instant);



#undef RUMI_DEFINE_SWITCHES_AND_INDICATORS_PLURAL
#undef RUMI_DEFINE_SWITCHES_AND_INDICATORS
#undef RUMI_DEFINE_INDICATORS_PLURAL
#undef RUMI_DEFINE_INDICATORS
#undef RUMI_DEFINE_SWITCHES


