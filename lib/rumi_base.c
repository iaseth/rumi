#include "rumi_base.h"

#include <stdlib.h>
#include <string.h>

Rumi
rumi_new (char *title)
{
	Rumi rumi = malloc(sizeof(struct RumiStruct));
	rumi_reset(rumi);
	strcpy(rumi->title, title);
	return rumi;
}

Rumi
rumi_new_child (Rumi rumi, char *title)
{
	Rumi child = rumi_new(title);
	child->parent = rumi;
	return child;
}

Rumi
rumi_delete (Rumi rumi)
{
	if (rumi != NULL) {
		free(rumi);
	}
	return NULL;
}

Rumi
rumi_reset (Rumi rumi)
{
	if (rumi != NULL) {
		rumi->parent = NULL;
		rumi->children = NULL;

		rumi->is_locked = false;
		rumi->key = RUMI_NO_KEY;

		rumi->title[0] = '\0';
		rumi->name[0] = '\0';
		rumi->suffix[0] = '\0';

		rumi->save_to_disk = false;

		rumi->show_debug = false;
		rumi->show_warnings = false;
		rumi->show_suggestions = false;

		rumi->show_color = true;
		rumi->show_date = true;
		rumi->show_time = true;
		rumi->show_instant = true;

		rumi->log_count = 0;
		rumi->ok_count = 0;
		rumi->error_count = 0;
		rumi->suggestion_count = 0;
		rumi->tip_count = 0;
		rumi->warning_count = 0;
	}
	return rumi;
}



const struct RumiRuStruct *
rumi_set_title (Rumi rumi, char *title)
{
	strcpy(rumi->title, title);
	return ru;
}

const struct RumiRuStruct *
rumi_set_name (Rumi rumi, char *name)
{
	strcpy(rumi->name, name);
	return ru;
}


