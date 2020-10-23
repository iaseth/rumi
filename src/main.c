#include "rumi.h"

#include <stdio.h>

void
rumi_with_ru ()
{
	Rumi rumi = ru->new("Rumi 1.0 (ru)");
	for (int i = 0; i < 20; ++i) {
		if (i % 2 == 0) {
			ru->ok(rumi, "%d is an even number", i);
		} else {
			ru->error(rumi, "%d is odd", i);
		}
	}
	rumi = ru->delete(rumi);
}

void
rumi_with_macros ()
{
	RUMI_NEW("Rumi 1.0 (macros)");
	RUMI_OK("Hello, Macros!");
	RUMI_DELETE();
}

void
rumi_vanilla ()
{
	Rumi rumi = rumi_new("Rumi 1.0 (vanilla)");
	rumi_ok(rumi, "Hello, %s!", "Vanilla");
	rumi = rumi_delete(rumi);
}

int
main (int argc, char const *argv[])
{
	// rumi_vanilla();
	// rumi_with_macros();
	rumi_with_ru();
}
