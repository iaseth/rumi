#include "rumi_log.h"

#include "rumi_colors.h"

#include <stdio.h>
#include <time.h>

int
rumi_log_internal (Rumi rumi, RumiColor c1, RumiColor c2, RumiColor c3, char *prefix, char *message)
{
	static int yday = 0;
	static char date_string[12] = "";

	printf("[%s%s%s] %2d. ", c1, prefix, rumi_color_reset, ++rumi->log_count);
	if (rumi->show_date || rumi->show_time) {
		time_t time_raw;
		time(&time_raw);
		struct tm *time_ptr = gmtime(&time_raw);
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
			if (rumi->show_color) {
				printf("on %s%02d:%02d:%02d%s ", rumi_color_fg_cyan, time_ptr->tm_hour, time_ptr->tm_min, time_ptr->tm_sec, rumi_color_reset);
			} else {
				printf("at %02d:%02d:%02d ", time_ptr->tm_hour, time_ptr->tm_min, time_ptr->tm_sec);
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
	rumi_log_internal(rumi, rumi_color_fg_green, rumi_color_fg_yellow, rumi_color_fg_green, "   OK   ", message);
}


