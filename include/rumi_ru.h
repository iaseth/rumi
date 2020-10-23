#ifndef RUMI_RU_H
#define RUMI_RU_H

#include "rumi_types.h"

struct RumiRuStruct;

typedef const struct RumiRuStruct* (*RumyLoggerFunction) (Rumi rumi, char *message, ...);
typedef const struct RumiRuStruct* (*RumySwitchFunction) ();
typedef const struct RumiRuStruct* (*RumyIndicatorFunction) ();

struct RumiRuStruct {
	RumyLoggerFunction ok;
	RumyLoggerFunction error;
};

extern const struct RumiRuStruct *const ru;



#endif