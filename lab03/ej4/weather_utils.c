#include <stdio.h>

#include "weather_utils.h"
#include "array_helpers.h"

int historical_min(WeatherTable a) {
    Weather i_weather = a[0][0][0];
    int abs_min_temp = i_weather._min_temp;
    for (unsigned int year = 0u; year < YEARS; ++year) {
        for (month_t month = january; month <= december; ++month) {
            for (unsigned int day = 0u; day < DAYS; ++day) {
                i_weather = a[year][month][day];
                if(i_weather._min_temp < abs_min_temp) {
                    abs_min_temp = i_weather._min_temp;
                }
            }
        }
    }
    return abs_min_temp;
}

void max_temp_annually(WeatherTable a, int max_temp_of[YEARS]) {
    Weather i_weather;
    int abs_max_temp;

    for (unsigned int year = 0u; year < YEARS; ++year) {
        i_weather = a[year][0][0];
        abs_max_temp = i_weather._max_temp;

        for (month_t month = january; month <= december; ++month) {
            for (unsigned int day = 0u; day < DAYS; ++day) {
                i_weather = a[year][month][day];
                if(i_weather._max_temp > abs_max_temp) {
                    abs_max_temp = i_weather._max_temp;
                }
            }
        }

        max_temp_of[year] = abs_max_temp;
    }
}

void max_rainfall_annually(WeatherTable a, month_t max_rf_of[YEARS]) {
    Weather i_weather;
    unsigned int max_monthly_rf_anually;
    unsigned int accumulated_rf_monthly;
    month_t the_month_max = january;

    for (unsigned int year = 0u; year < YEARS; ++year) {
        max_monthly_rf_anually = 0u;

        for (month_t month = january; month <= december; ++month) {
            accumulated_rf_monthly = 0u;

            for (unsigned int day = 0u; day < DAYS; ++day) {
                i_weather = a[year][month][day];
                accumulated_rf_monthly = accumulated_rf_monthly + i_weather._rainfall;
            }

            if(accumulated_rf_monthly > max_monthly_rf_anually) {
                max_monthly_rf_anually = accumulated_rf_monthly;
                the_month_max = month;
            }
        }

        max_rf_of[year] = the_month_max;
    }
}