#include "rumi.h"

#include <stdio.h>

void
rumi_no_macros ()
{
	Rumi rumi = ru->new("rumi_no_macros");
	for (int i = 0; i < 100000; ++i) {
		if (i % 2 == 0) {
			ru->ok(rumi, "This is an even number");
		} else {
			ru->error(rumi, "This is odd");
		}
	}
	rumi = ru->delete(rumi);
}

void rumi_with_macros ()
{
	RUMI_NEW("Rumi 1.0");
	printf("%s\n", rumi->title);
	RUMI_DELETE();
}

int
main (int argc, char const *argv[])
{
	rumi_no_macros();
}
