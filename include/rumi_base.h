#ifndef RUMI_BASE_H
#define RUMI_BASE_H

#include "rumi_types.h"

Rumi rumi_new (char *title);
Rumi rumi_reset (Rumi rumi);
Rumi rumi_new_child (Rumi rumi);
Rumi rumi_delete (Rumi rumi);



#endif