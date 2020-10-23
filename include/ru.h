#ifndef RUMI_RU_H
#define RUMI_RU_H

#include "rumi_types.h"

struct RumiRuStruct;

typedef const struct RumiRuStruct* (*RumyLoggerFunction) (Rumi rumi, char *message, ...);
typedef const struct RumiRuStruct* (*RumySwitchFunction) (Rumi rumi);
typedef bool (*RumyIndicatorFunction) (Rumi rumi);

struct RumiRuStruct {
	int status_code;

	Rumi (*new) (char *title);
	Rumi (*new_child) (Rumi rumi, char *title);
	Rumi (*delete) (Rumi rumi);

	RumyLoggerFunction ok;
	RumyLoggerFunction error;

	RumyLoggerFunction suggest;
	RumyLoggerFunction tip;
	RumyLoggerFunction warn;

	RumyLoggerFunction good;
	RumyLoggerFunction bad;
	RumyLoggerFunction minate;
};

extern const struct RumiRuStruct *const ru;



#endif