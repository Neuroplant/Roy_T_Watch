#include "constants.h"

int32_t unix_zeit(RTC_Date value)
{
	const short tage_seit_jahresanfang[12] = /* Anzahl der Tage seit Jahresanfang ohne Tage des aktuellen Monats und ohne Schalttag */
	{ 0,31,59,90,120,151,181,212,243,273,304,334 };

	int schaltjahre = ((value.year - 1) - 1968) / 4 /* Anzahl der Schaltjahre seit 1970 (ohne das evtl. laufende Schaltjahr) */
		- ((value.year - 1) - 1900) / 100
		+ ((value.year - 1) - 1600) / 400;

	int32_t tage_seit_1970 = (value.year - 1970) * 365 + schaltjahre
		+ tage_seit_jahresanfang[value.month - 1] + value.day - 1;

	if ((value.month > 2) && (value.year % 4 == 0 && (value.year % 100 != 0 || value.year % 400 == 0)))
		tage_seit_1970 += 1; /* +Schalttag, wenn jahr Schaltjahr ist */

	return value.second + 60 * (value.minute + 60 * (value.hour + 24 * tage_seit_1970));
};

int moon_phase(RTC_Date Value)
{
    int y = Value.year;
    int m = Value.month;
    int d = Value.day;

    /*
      calculates the moon phase (0-7), accurate to 1 segment.
      0 = > new moon.
      4 => full moon.
      */

    int c, e;
    double jd;
    int b;

    if (m < 3) {
        y--;
        m += 12;
    }
    ++m;
    c = 365.25 * y;
    e = 30.6 * m;
    jd = c + e + d - 694039.09;  /* jd is total days elapsed */
    jd /= 29.53;           /* divide by the moon cycle (29.53 days) */
    b = jd;		   /* int(jd) -> b, take integer part of jd */
    jd -= b;		   /* subtract integer part to leave fractional part of original jd */
    b = jd * 8 + 0.5;	   /* scale fraction from 0-8 and round by adding 0.5 */
    b = b & 7;		   /* 0 and 8 are the same so turn 8 into 0 */
    return b;
}