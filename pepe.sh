#! /bin/bash

# chmod +x pepe.sh

cd ./lab05/ej1a

#Compilar:
gcc -Wall -Werror -Wextra -pedantic -std=c99 -c stack.c

cd ./reverse

gcc -Wall -Werror -Wextra -pedantic -std=c99 -g -c array_helpers.c reverse.c
gcc -Wall -Werror -Wextra -pedantic -std=c99 -g array_helpers.o reverse.o ../stack.o -o script

#Probar:
./script ./input/example-unsorted.in


#> weather_cordoba.out
#diff ../input/weather_cordoba.in weather_cordoba.out

# Eliminador de archivos generados:
#rm list.o array_helpers.o main.o script
cd ../..


# tar -czvf labXX_avila_wilfredo.tar.gz labXX
# tar -xf labXX_avila_wilfredo.tar.gz