/* 
 * Program 			: list.c
 * Deskripsi 		: Body list berkait dgn representasi fisik
 * Nama 			: Adriana Anggita Daeli 
 * Tanggal			: 26 Juli 2021
 * Compiler			: Dev-C++
 * ==============================================================
 */

#include "list.h"

#ifndef list_C
#define list_C

/* Body fucntion / procedure */
nodeL CreateNodeList (char word[]) 
{  
	/* Konstruktor Node List */
	/* IS : L sembarang */
	/* FS : Terbentuk List Kosong */
	
	/* Kamus Data */
	nodeL newNode;
	
	/* Algoritma */
    // Cek string
    if (word == NULL) {
        return NULL;
    }

    // Alokasi node
    newNode = (nodeL)malloc(sizeof(NodeList));

    // Memasukkan string
    strcpy(newNode->string, word);
    newNode->next = NULL;
    
    return newNode;
}

void ListPush (nodeL *list, char word[]) 
{
	/* Menambahkan elemen list di akhir (elemen terakhir adalah yang baru) */
	/* IS : L mungkin Kosong */
	/* FS : Melakukan alokasi sebuah elemen dan menggabungkan dengan list yang ada*/
    
	/* Kamus Data */
	nodeL newNode;
    nodeL currentNode;
	
	/* Algoritma */
    // Alokasi
    newNode = CreateNodeList(word);
    
    // Masukkan list yang akan diisi ke dalam temp var
    currentNode = *list;
	
    // Kalau list kosong
    if (*list == NULL) {
        *list = newNode;
        return;
    }
    
    // Kalau list sudah berisi
    while (currentNode->next != NULL) {
        currentNode = currentNode->next;    // bergerak menuju node yg blm diisi
    }
    currentNode->next = newNode;
    
}

#endif
