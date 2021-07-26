#include "utils.h"

#ifndef utils_C
#define utils_C

/*********** PROTOTYPE ****************/
/* Mengecek apakah sebuah karakter merupakan operand atau operator*/
bool isNumeric(char ch) 
{
    return (ch >= '0' && ch <= '9');
}

#endif
