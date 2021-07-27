/* 
 * Program 			: list.h
 * Deskripsi 		: Deklarasi list  berkait dgn representasi list
 * Nama 			: Adriana Anggita Daeli 
 * Tanggal			: 26 Juli 2021
 * Compiler			: Dev-C++
 * ==============================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef list_H
#define list_H

#define MAX_STR 100

typedef struct tNodeList *nodeL;	
typedef struct tNodeList {
	char string [MAX_STR];
	nodeL next;
}NodeList;

nodeL CreateNodeList (char word[]);
/* Konstruktor node List */
/* IS : L sembarang */
/* FS : Terbentuk List Kosong */

void ListPush (nodeL *list, char word[]);
/* Menambahkan elemen list di akhir (elemen terakhir adalah yang baru) */
/* IS : L mungkin Kosong */
/* FS : Melakukan alokasi sebuah elemen dan menggabungkan dengan list yang ada*/

#endif
