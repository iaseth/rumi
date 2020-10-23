#include "rumi_log.h"

#include "rumi_colors.h"

#include <stdio.h>
#include <time.h>

int
rumi_log_internal (Rumi rumi, RumiColor c1, RumiColor c2, RumiColor c3, char *prefix, char *message, char *postscript)
{
	static struct tm *time_ptr = NULL;
	static int yday = 0;
	static char date_string[12] = "";

	static int tv_sec = 0;
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

			int milliseconds = ts.tv_nsec / 1e6;
			if (rumi->show_color) {
				printf("at %s%s%s %03dms ", rumi_color_fg_cyan,
					time_string, rumi_color_reset, milliseconds);
			} else {
				printf("at %s %03dms ",
					time_string, milliseconds);
			}
		}
	}

	if (rumi->show_color) {
		printf("(%s%s%s) %s\n", c2, rumi->title, rumi_color_reset, message);
	} else {
		printf("(%s) %s\n", rumi->title, message);
	}
	return 0;
}

void
rumi_ok (Rumi rumi, char *message, char *postscript)
{
	rumi_log_internal(rumi, rumi_color_fg_green, rumi_color_fg_green, rumi_color_fg_yellow, "   OK   ", message, postscript);
}


