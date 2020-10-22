#ifndef RUMI_LOG_H
#define RUMI_LOG_H

#include "rumi_types.h"

int rumi_log_internal (Rumi rumi, RumiColor c1, RumiColor c2, RumiColor c3, char *prefix, char *message);

void rumi_log (Rumi rumi, char *message);



#endif