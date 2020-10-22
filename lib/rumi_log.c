#include "rumi_log.h"

#include "rumi_colors.h"

#include <stdio.h>

int
rumi_log_internal (Rumi rumi, RumiColor c1, RumiColor c2, RumiColor c3, char *prefix, char *message)
{
	printf("[%s%s%s] %2d. ", c1, prefix, rumi_color_reset, ++rumi->log_count);
	printf("(%s%s%s) ", c2, rumi->title, rumi_color_reset);
	printf("Rumi says: %s\n", message);
	return 0;
}

void
rumi_ok (Rumi rumi, char *message)
{
	rumi_log_internal(rumi, rumi_color_fg_green, rumi_color_fg_yellow, rumi_color_fg_green, "   OK   ", message);
}


