/* 
 * Program 			: calstd.h
 * Deskripsi 		: Deklarasi list berkait kalkulator standard
 * Nama 			: Adriana Anggita Daeli 
 * Tanggal			: 26 Juli 2021
 * Compiler			: Dev-C++
 * ==============================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <math.h>
#include <stdbool.h>
#include "postfix.h"
#include "bintree.h"

#ifndef calstd_H
#define calstd_H

int CalStd();
/* Kalkulator standard untuk menghitung sebuah ekspresi */
/* meggunakan pohon ekspresi */
/* I.S. : Program belum berjalan */
/* F.S. : Layar akan menampilkan ekspresi infox, postfix */
/*		  pohon, dan juga hasil kalkulasiny				 */

nodeT BuildTreeInterface(char *);
/* Pemilah karakter operator atau operand dan memprosesnya */
/* karakter operand terlebih dahulu sebelum dimasukkan ke dalam tree */
/* I.S. : Pohon belum terkalkulasi */
/* F.S. : Mengembalikan hasil kalkulasi */

bool ValidChar(char *op);
/* Pemilah karakter yang tidak valid*/

bool ValidParenthesized(char *op); 
/* Memilah operator parenthesis yang tidak valid */

bool ValidOp(char *op);
/* Mengecek operais yang tidak valid*/
 
#endif
