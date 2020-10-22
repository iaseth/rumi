#include "rumi_base.h"

#include <stdlib.h>
#include <string.h>

Rumi
rumi_new (char *title)
{
	Rumi rumi = malloc(sizeof(Rumi_t));
	strcpy(rumi->title, title);
	return rumi;
}

Rumi
rumi_new_child (Rumi rumi)
{
	return NULL;
}

Rumi
rumi_delete (Rumi rumi)
{
	if (rumi != NULL) {
		free(rumi);
	}
	return NULL;
}


