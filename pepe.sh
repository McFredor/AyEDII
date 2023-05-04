#! /bin/bash

# chmod +x pepe.sh

cd ./lab04/ej0/d/dynamic

#Compilar:
gcc -Wall -Werror -Wextra -pedantic -std=c99 -g -c main.c array_helpers.c
gcc -Wall -Werror -Wextra -pedantic -std=c99 -g main.o array_helpers.o -o script

#Probar:
./script ../input/example-easy.in


#> weather_cordoba.out
#diff ../input/weather_cordoba.in weather_cordoba.out

# Eliminador de archivos generados:
rm main.o
cd ../..


# -cvzf