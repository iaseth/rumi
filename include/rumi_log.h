#ifndef RUMI_LOG_H
#define RUMI_LOG_H

#include "rumi_types.h"
#include "ru.h"

int rumi_log_internal (Rumi rumi, RumiColor c1, RumiColor c2, RumiColor c3, char *prefix, char *message, ...);

const struct RumiRuStruct* rumi_ok (Rumi rumi, char *message, ...);
const struct RumiRuStruct* rumi_error (Rumi rumi, char *message, ...);

const struct RumiRuStruct* rumi_suggest (Rumi rumi, char *message, ...);
const struct RumiRuStruct* rumi_tip (Rumi rumi, char *message, ...);
const struct RumiRuStruct* rumi_warn (Rumi rumi, char *message, ...);

const struct RumiRuStruct* rumi_good (Rumi rumi, char *message, ...);
const struct RumiRuStruct* rumi_bad (Rumi rumi, char *message, ...);

const struct RumiRuStruct* rumi_nate (Rumi rumi, char *message, ...);



#endif