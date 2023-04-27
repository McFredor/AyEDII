#! /bin/bash

# chmod +x pepe.sh

cd ./lab03/ej4

#Compilar:
gcc -Wall -Werror -Wextra -pedantic -std=c99 -c array_helpers.c weather.c weather_utils.c main.c
gcc -Wall -Werror -Wextra -pedantic -std=c99 array_helpers.o weather.o weather_utils.o main.o -o weather

#Probar:


#> weather_cordoba.out
#diff ../input/weather_cordoba.in weather_cordoba.out

# Eliminador de archivos generados:
rm array_helpers.o weather.o  weather_utils.o main.o
#cd ../..

