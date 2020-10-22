#include "rumi.h"

#include <stdio.h>

int
main (int argc, char const *argv[])
{
	Rumi_new("Rumi 1.0");
	printf("%s\n", rumi->title);
	Rumi_delete;
}
