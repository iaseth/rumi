#include "rumi.h"

#include <stdio.h>

void
rumi_no_macros ()
{
	Rumi rumi = rumi_new("rumi_no_macros");
	for (int i = 0; i < 20; ++i) {
		rumi_ok(rumi, "Hello");
	}
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
	rumi_no_macros();
}
