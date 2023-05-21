#! /bin/bash

# chmod +x pepe.sh

cd ./lab05/ej4/d

#Compilar:
gcc -Wall -Werror -Wextra -pedantic -std=c99 -g -c clone.c
gcc -Wall -Werror -Wextra -pedantic -std=c99 -g -ggdb3 clone.o  -o script

#Probar:
#./script 


#> weather_cordoba.out
#diff ../input/weather_cordoba.in weather_cordoba.out

# Eliminador de archivos generados:
#rm *.o 
cd ../..


# tar -czvf labXX_avila_wilfredo.tar.gz labXX
# tar -xf labXX_avila_wilfredo.tar.gz