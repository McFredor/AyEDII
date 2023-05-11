#! /bin/bash

# chmod +x pepe.sh

cd ./lab04/ej3

#Compilar:
gcc -Wall -Werror -Wextra -pedantic -std=c99 -g -c list.c array_helpers.c main.c
gcc -Wall -Werror -Wextra -pedantic -std=c99 -g list.o array_helpers.o main.o -o script

#Probar:
./script ./input/example-unsorted.in


#> weather_cordoba.out
#diff ../input/weather_cordoba.in weather_cordoba.out

# Eliminador de archivos generados:
rm list.o array_helpers.o main.o script
cd ../..


# tar -czvf labXX_avila_wilfredo.tar.gz labXX
# tar -xf labXX_avila_wilfredo.tar.gz