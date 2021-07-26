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

nodeT BuildTreeInterface(char *);

int CalStandard();

#endif
