#ifndef _WEATHER_UTILS
#define _WEATHER_UTILS

#include "weather.h"
#include "array_helpers.h"

int historical_min(WeatherTable a);
/*
    Obtains the lowest historical minimum temperature recorded in
    the city of Córdoba according to the data from the 'a' array.
*/

void max_temp_annually(WeatherTable a, int max_temp_of[YEARS]);
/*
    A "procedure" that records the highest maximum temperature
    for each year and saves it in 'max_temp_of[year]'.
*/

void max_rainfall_annually(WeatherTable a, month_t max_rf_of[YEARS]);
/*
    A "procedure" that records the month with the highest amount
    of rainfall for each year and saves it in 'max_rf_of[year]'.
*/

#endif