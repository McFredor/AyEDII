#ifndef __STRUNCS_H__
#define __STRUNCS_H__

#include <stdlib.h>

/**
 * @brief Calcula la longitud de la cadena apuntada por str. 
**/
size_t string_length(const char *str);

/**
 * @brief Devuelve una nueva cadena en memoria dinámica que se obtiene tomando los
 * caracteres de stre que son distintos. 
**/
char *string_filter(const char *str, char c);

#endif