#include "rumi_log.h"

#include "rumi_colors.h"

#include <stdio.h>
#include <time.h>

int
rumi_log_internal (Rumi rumi, RumiColor c1, RumiColor c2, RumiColor c3, char *prefix, char *message, va_list argptr)
{
	static struct tm *time_ptr = NULL;
	static int yday = 0;
	static char date_string[12] = "";

	static int tv_sec = 0;
	static int milliseconds = 0;
	static int microseconds = 0;
	static char time_string[12] = "";

	if (rumi->show_color) {
		printf("[%s%s%s] %2d. ", c1, prefix, rumi_color_reset, ++rumi->log_count);
	} else {
		printf("[%s] %2d. ", prefix, ++rumi->log_count);
	}

	if (rumi->show_date || rumi->show_time) {
		struct timespec ts;
		timespec_get(&ts, TIME_UTC);
		// only call localtime() if tv_sec has changed.
		if (tv_sec != ts.tv_sec) {
			time_ptr = localtime(&(ts.tv_sec));
		}

		if (rumi->show_date) {
			// only computer date_string if yday has changed
			if (yday != time_ptr->tm_yday) {
				yday = time_ptr->tm_yday;
				int day = time_ptr->tm_mday;
				int month = time_ptr->tm_mon + 1;
				int year = 1900 + time_ptr->tm_year;
				sprintf(date_string, "%02d.%02d.%04d", day, month, year);
			}
			if (rumi->show_color) {
				printf("on %s%s%s ", rumi_color_fg_yellow, date_string, rumi_color_reset);
			} else {
				printf("on %s ", date_string);
			}
		}

		if (rumi->show_time) {
			// only computer time_string if tv_sec has changed
			if (tv_sec != ts.tv_sec) {
				tv_sec = ts.tv_sec;
				sprintf(time_string, "%02d:%02d:%02d", time_ptr->tm_hour, time_ptr->tm_min, time_ptr->tm_sec);
			}

			milliseconds = ts.tv_nsec / 1000000;
			microseconds = (ts.tv_nsec / 1000) % 1000;
			if (rumi->show_color) {
				printf("at %s%s%s %03d.%03d ms ",
					rumi_color_fg_cyan, time_string, rumi_color_reset,
					milliseconds, microseconds
				);
			} else {
				printf("at %s %03d.%03d ms ",
					time_string,
					milliseconds, microseconds
				);
			}
		}
	}

	char full_message[200];
	vsprintf(full_message, message, argptr);

	if (rumi->show_color) {
		printf("(%s%s%s) %s%s%s\n",
			c2, rumi->title, rumi_color_reset,
			c3, full_message, rumi_color_reset
		);
	} else {
		printf("(%s) %s.\n", rumi->title, full_message);
	}
	return 0;
}



#define RUMI_LOG_INTERNAL_CALLER(c1, c2, c3, prefix) \
	va_list argptr;                                  \
	va_start(argptr, message);                       \
	rumi_log_internal(rumi,                          \
		rumi_color_fg_ ## c1,                        \
		rumi_color_fg_ ## c2,                        \
		rumi_color_fg_ ## c3,                        \
		prefix, message, argptr);                    \
	va_end(argptr);                                  \
	return ru;

const struct RumiRuStruct *
rumi_ok (Rumi rumi, char *message, ...)
{
	rumi->ok_count++;
	RUMI_LOG_INTERNAL_CALLER(green, green, green, "   OK   ");
}

const struct RumiRuStruct *
rumi_error (Rumi rumi, char *message, ...)
{
	rumi->error_count++;
	RUMI_LOG_INTERNAL_CALLER(red, red, red, " ERROR! ");
}

const struct RumiRuStruct *
rumi_suggest (Rumi rumi, char *message, ...)
{
	rumi->suggestion_count++;
	RUMI_LOG_INTERNAL_CALLER(yellow, cyan, yellow, "  SUGG  ");
}

const struct RumiRuStruct *
rumi_tip (Rumi rumi, char *message, ...)
{
	rumi->tip_count++;
	RUMI_LOG_INTERNAL_CALLER(magenta, cyan, yellow, "  TIP!  ");
}

const struct RumiRuStruct *
rumi_warn (Rumi rumi, char *message, ...)
{
	rumi->warning_count++;
	RUMI_LOG_INTERNAL_CALLER(cyan, red, yellow, "  WARN  ");
}

const struct RumiRuStruct *
rumi_good (Rumi rumi, char *message, ...)
{
	RUMI_LOG_INTERNAL_CALLER(green, magenta, yellow, "  GOOD  ");
}

const struct RumiRuStruct *
rumi_bad (Rumi rumi, char *message, ...)
{
	RUMI_LOG_INTERNAL_CALLER(red, magenta, yellow, "   BAD  ");
}

const struct RumiRuStruct *
rumi_nate (Rumi rumi, char *message, ...)
{
	RUMI_LOG_INTERNAL_CALLER(yellow, magenta, yellow, "  NATE  ");
}

#undef RUMI_LOG_INTERNAL_CALLER


