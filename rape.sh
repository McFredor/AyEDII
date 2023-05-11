#! /bin/bash

# chmod +x rape.sh

cd ./lab04/ej2

#Compilar:
gcc -Wall -Werror -Wextra -pedantic -std=c99 -g -c counter.c main.c
gcc -Wall -Werror -Wextra -pedantic -std=c99 -g counter.o main.o -o script

#Probar:
./script ./input/balanced.in

#> weather_cordoba.out
#diff ../input/weather_cordoba.in weather_cordoba.out

# Eliminador de archivos generados:
#rm array_helpers.o list.o main.o script

cd ../..

