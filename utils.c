/* 
 * Program 			: utils.c
 * Deskripsi 		: Body list berkait dgn modul tambahan
 * Nama 			: Adriana Anggita Daeli 
 * Tanggal			: 26 Juli 2021
 * Compiler			: Dev-C++
 * ==============================================================
 */


#include "utils.h"

#ifndef utils_C
#define utils_C

bool isNumeric(char ch) 
{
    /* Mengecek apakah sebuah karakter merupakan operand atau operator*/
	return (ch >= '0' && ch <= '9');
}

#endif
