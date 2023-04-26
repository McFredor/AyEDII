#! /bin/bash

# chmod +x pepe.sh

cd ./lab03/ej3

#Compilar:
gcc -Wall -Werror -Wextra -pedantic -std=c99 -c pattern_manager.c main.c
gcc -Wall -Werror -Wextra -pedantic -std=c99 pattern_manager.o main.o -o mysort

#Probar:
./mysort ./phrase-basic.in
sleep 1
echo ""

./mysort ./phrase-hack.in
sleep 1
echo ""

./mysort ./phrase1.in
sleep 1
echo ""

./mysort ./phrase2.in
sleep 1
echo ""

./mysort ./phrase3.in
sleep 1
echo ""

./mysort ./phrase4.in
sleep 1
echo ""


#> weather_cordoba.out
#diff ../input/weather_cordoba.in weather_cordoba.out

# Eliminador de archivos generados:
rm helpers.o sort.o main.o
cd ../..

