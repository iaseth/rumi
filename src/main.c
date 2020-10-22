#include "rumi.h"

#include <stdio.h>

int
main (int argc, char const *argv[])
{
	Rumi rumi = rumi_new("Rumi 1.0");
	rumi = rumi_delete(rumi);
}
