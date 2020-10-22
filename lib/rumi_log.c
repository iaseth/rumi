#include "rumi_log.h"

#include "rumi_colors.h"

#include <stdio.h>
#include <time.h>

int
rumi_log_internal (Rumi rumi, RumiColor c1, RumiColor c2, RumiColor c3, char *prefix, char *message)
{
	static int yday = 0;
	static char date_string[12] = "";

	static int tv_sec = 0;
	static char time_string[12] = "";

	printf("[%s%s%s] %2d. ", c1, prefix, rumi_color_reset, ++rumi->log_count);
	if (rumi->show_date || rumi->show_time) {
		struct timespec ts;
		timespec_get(&ts, TIME_UTC);
		struct tm *time_ptr = localtime(&(ts.tv_sec));
		if (rumi->show_date) {
			if (yday != time_ptr->tm_yday) {
				yday = time_ptr->tm_yday;
				int day = time_ptr->tm_mday;
				int month = time_ptr->tm_mon + 1;
				int year = time_ptr->tm_year % 100;
				sprintf(date_string, "%02d.%02d.%02d", day, month, year);
			}
			if (rumi->show_color) {
				printf("on %s%s%s ", rumi_color_fg_yellow, date_string, rumi_color_reset);
			} else {
				printf("on %s ", date_string);
			}
		}

		if (rumi->show_time) {
			if (tv_sec != ts.tv_sec) {
				tv_sec = ts.tv_sec;
				sprintf(time_string, "%02d:%02d:%02d", time_ptr->tm_hour, time_ptr->tm_min, time_ptr->tm_sec);
			}

			int milliseconds = ts.tv_nsec / 1e6;
			if (rumi->show_color) {
				printf("at %s%s%s|%03dms ", rumi_color_fg_cyan,
					time_string, rumi_color_reset, milliseconds);
			} else {
				printf("at %s|%03dms ",
					time_string, milliseconds);
			}
		}
	}
	printf("(%s%s%s) ", c2, rumi->title, rumi_color_reset);
	printf("Rumi says: %s\n", message);
	return 0;
}

void
rumi_ok (Rumi rumi, char *message)
{
	rumi_log_internal(rumi, rumi_color_fg_green, rumi_color_fg_green, rumi_color_fg_yellow, "   OK   ", message);
}


