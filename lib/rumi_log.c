#include "rumi_log.h"

#include <stdio.h>

int
rumi_log_internal (Rumi rumi, RumiColor c1, RumiColor c2, RumiColor c3, char *prefix, char *message)
{
	return 0;
}

void
rumi_log (Rumi rumi, char *message)
{
	printf("Rumi says: %s\n", message);
}


