#include "rumi.h"

#include <stdio.h>

void
rumi_no_macros ()
{
	Rumi rumi = rumi_new("rumi_no_macros");
	printf("%s\n", rumi->title);
	rumi = rumi_delete(rumi);
}

void rumi_with_macros ()
{
	Rumi_new("Rumi 1.0");
	printf("%s\n", rumi->title);
	Rumi_delete;
}

int
main (int argc, char const *argv[])
{
	rumi_with_macros();
}
