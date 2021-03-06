#ifndef RUMI_TYPES_H
#define RUMI_TYPES_H

#include <stdbool.h>


#define RUMI_MAX_NAME_LENGTH 100
#define RUMI_MIN_CHILDREN 16

#define RUMI_NO_KEY 0


typedef char *RumiColor;

struct RumiStruct;
typedef struct RumiStruct *Rumi;


struct RumiStruct {
	struct RumiStruct *parent;
	struct RumiStruct **children;

	bool is_locked;
	int key;

	char title [RUMI_MAX_NAME_LENGTH];
	char name [RUMI_MAX_NAME_LENGTH];
	char suffix [RUMI_MAX_NAME_LENGTH];

	bool save_to_disk;
	char filename [RUMI_MAX_NAME_LENGTH];

	bool show_debug;
	bool show_warnings;
	bool show_suggestions;

	bool show_color;
	bool show_date;
	bool show_time;
	bool show_instant;

	int max_width;

	int log_count;
	int ok_count;
	int error_count;
	int suggestion_count;
	int tip_count;
	int warning_count;
};



#endif