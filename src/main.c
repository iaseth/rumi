#include "rumi.h"

#include <stdio.h>

void
rumi_no_macros ()
{
	Rumi rumi = rumi_new("rumi_no_macros");
	printf("%s\n", rumi->title);
	rumi = rumi_delete(rumi);
}

int
main (int argc, char const *argv[])
{
	Rumi_new("Rumi 1.0");
	printf("%s\n", rumi->title);
	Rumi_delete;
}
