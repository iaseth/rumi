#ifndef RUMI_LOG_H
#define RUMI_LOG_H

#include "rumi_types.h"

int rumi_log_internal (Rumi rumi, RumiColor c1, RumiColor c2, RumiColor c3, char *prefix, char *message, ...);

void rumi_ok (Rumi rumi, char *message, ...);

#define rumi_error(rumi, ...)                                       \
	rumi_log_internal(                                              \
		rumi,                                                       \
		rumi_color_fg_red, rumi_color_fg_red, rumi_color_fg_green,  \
		"  ERROR ", __VA_ARGS__                                     \
	)



#endif