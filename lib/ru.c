#include "ru.h"

#include "rumi_base.h"
#include "rumi_log.h"

struct RumiRuStruct ru_struct = {
	.status_code = 0,
	.new = &rumi_new,
	.new_child = &rumi_new_child,
	.delete = &rumi_delete,

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
