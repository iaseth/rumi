#ifndef RUMI_RU_H
#define RUMI_RU_H

#include "rumi_types.h"

struct RumiRuStruct;

typedef const struct RumiRuStruct* (*RumyLoggerFunction) (Rumi rumi, char *message, ...);
typedef const struct RumiRuStruct* (*RumySwitchFunction) (Rumi rumi);
typedef bool (*RumyIndicatorFunction) (Rumi rumi);

struct RumiRuStruct {
	RumyLoggerFunction ok;
	RumyLoggerFunction error;
};

extern const struct RumiRuStruct *const ru;



#endif