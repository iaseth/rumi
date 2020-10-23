#include "rumi_ru.h"

#include "rumi_log.h"

struct RumiRuStruct ru_struct = {
	.ok = &rumi_ok,
	.error = &rumi_error
};

const struct RumiRuStruct *const ru = &ru_struct;
