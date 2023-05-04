/*
@file array_helpers.c
@brief Array Helpers method implementation
*/
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "array_helpers.h"

static const int EXPECTED_DIM_VALUE = 2;

static const char* CITY_NAMES[CITIES] = {
    "Cordoba", "Rosario", "Posadas", "Tilcara", "Bariloche"};
static const char* SEASON_NAMES[SEASONS] = {"low", "high"};

void array_dump(BakeryProductTable a)
{
    for (unsigned int city = 0u; city < CITIES; ++city)
    {
        for (unsigned int season = 0u; season < SEASONS; ++season)
        {
            fprintf(stdout, "%s in %s season: flour (%u,%u) Yeast (%u,%u) Butter (%u,%u) Sales value %u",
                    CITY_NAMES[city], SEASON_NAMES[season], a[city][season].flour_cant,
                    a[city][season].flour_price, a[city][season].yeast_cant,
                    a[city][season].yeast_price, a[city][season].butter_cant,
                    a[city][season].butter_price, a[city][season].sale_value);
            fprintf(stdout, "\n");
        }
    }
}

unsigned int best_profit(BakeryProductTable a)
{
    unsigned int max_profit = 0u;
    unsigned int cost = 0u;
    
    for (unsigned int city = 0u; city < CITIES; ++city) {
        for (unsigned int season = 0u; season < SEASONS; ++season) {
            BakeryProduct product;
            product = a[city][season];
            unsigned int product_profit;

            cost =  (product.flour_cant * product.flour_price)
                   +(product.yeast_cant * product.yeast_price)
                   +(product.butter_cant * product.butter_price);
            product_profit = product.sale_value - cost;

            if (city==0 && season==0) {max_profit = product_profit;}
            if (product_profit > max_profit) {max_profit = product_profit;}
        }
    }
    return max_profit;
}

void array_from_file(BakeryProductTable array, const char* filepath)
{
    FILE* file = NULL;

    unsigned int i = 0;
    unsigned int j = 0;
    while (filepath[i] != '\0')
    {
        i++;
    }
    while (filepath[i-3] == EXPECTED_PRODUCT_FILE_FORMAT[j] && j < 3) {
        i++;
        j++;
    }
    if (j == 3) {
        fprintf(stderr, "File is in wrong format.\n");
        exit(EXIT_FAILURE);
    }

    file = fopen(filepath, "r");
    if (file == NULL)
    {
        fprintf(stderr, "File does not exist.\n");
        exit(EXIT_FAILURE);
    }
    
    unsigned int k_city = 0u;
    unsigned int k_season = 0u;
    bool is_data_correct;
    
    while (!feof(file))
    {
        int res = fscanf(file, "##%u??%u ", &k_city, &k_season);
        is_data_correct = (k_season < SEASONS) && (k_city < CITIES);

        if (res != EXPECTED_DIM_VALUE)
        {
            fprintf(stderr, "Invalid file.\n");
            exit(EXIT_FAILURE);
        }
        if (!is_data_correct)
        {
            fprintf(stderr, "Exist a wrong City or Season.\n");
            exit(EXIT_FAILURE);
        }

        BakeryProduct bakery_product = bakery_product_from_file(file);
        array[k_city][k_season] = bakery_product;

        /* COMPLETADO */
    }
    fclose(file);
}
