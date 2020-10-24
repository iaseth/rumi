#ifndef RUMI_BASE_H
#define RUMI_BASE_H

#include "rumi_types.h"
#include "ru.h"

Rumi rumi_new (char *title);
Rumi rumi_new_child (Rumi rumi, char *title);
Rumi rumi_delete (Rumi rumi);

Rumi rumi_reset (Rumi rumi);

const struct RumiRuStruct* rumi_set_title (Rumi rumi, char *title);
const struct RumiRuStruct* rumi_set_name (Rumi rumi, char *name);



#endif