#! /bin/bash

# chmod +x pepe.sh

cd ./lab02/ej5

#Compilar:
gcc -Wall -Werror -Wextra -pedantic -std=c99 -g -c array_helpers.c fixstring.c main.c sort.c sort_helpers.c
gcc -Wall -Werror -Wextra -pedantic -std=c99 -g -no-pie array_helpers.o fixstring.o main.o sort.o sort_helpers.o -o word_sorter

#Probar:

# Eliminador de archivos generados:
rm fixstring.o main.o main
cd ../..

