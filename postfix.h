/* 
 * Program 			: postfix.h
 * Deskripsi 		: Deklarasi list berkait dgn rerpresentasi 
 					  stack untuk proses konversi notasi 
					  infix to postfix
 * Nama 			: Adriana Anggita Daeli 
 * Tanggal			: 26 Juli 2021
 * Compiler			: Dev-C++
 * ==============================================================
 */

#include <stdbool.h>
#include <ctype.h>
#include "list.h"

#ifndef postfix_H
#define postfix_H

typedef struct tNodeStack *nodeS;	// alias address
typedef struct tNodeStack {
	int *array;                     // nilai operator
    int top;                        // penanda top
}NodeStack;

nodeS CreateNodeStack(int length);
/* Konstruktor node stack */
/* I.S. : Stack sembarang */
/* F.S. : Lebar screen komputer diketahui */

bool StackIsEmpty(nodeS stack);
/* Mengirim true jika stack kosong */

char StackGet(nodeS stack);
/* Mengembalikan nilai stack di top */

void StackPush(nodeS stack, char op);
/* Menambahkan op sebagai elemen Stack */
/* I.S. : Stack mungkin kosong */
/* F.S. : op menjadi TOP yang baru, TOP bertambah 1 */

char StackPop(nodeS stack);
/* Menghapus TOP dari stack*/
/* I.S. : Stack tidak mungkin kosong */
/* F.S. : TOP berganti menjadi elemen yang sebelumnya berada di bawah TOP */

int GetPrecendence(char ch);
/* Mengembalikan nilai prioritas dari ch */
/* Referensi : https://www.geeksforgeeks.org/infix-to-postfix-using-different-precedence-values-for-in-stack-and-out-stack/ */
/* Dimodifikasi oleh : Adriana Anggita Daeli */

int InfixToPostfix(char *infix, char *postfix);
/* Mengkonversi notasi infix ke notasi postfix */
/* I.S. : Notasi infix bisa berisi sebuah ekspresi atau tidak*/
/* F.S. : Notasi postfix berisi hasil konversi notasi infix */
/* Referensi : https://www.geeksforgeeks.org/stack-set-2-infix-to-postfix/ */
/* Dimodifikasi oleh : Adriana Anggita Daeli */


#endif
