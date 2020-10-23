#include "ru.h"

#include "rumi_log.h"

struct RumiRuStruct ru_struct = {
	.ok = &rumi_ok,
	.error = &rumi_error,

	.suggest = &rumi_suggest,
	.tip = &rumi_tip,
	.warn = &rumi_warn,

	.good = &rumi_good,
	.bad = &rumi_bad,
	.minate = &rumi_nate
};

const struct RumiRuStruct *const ru = &ru_struct;
