/* 
 * Program 			: list.c
 * Deskripsi 		: Body list berkait dgn representasi fisik
 * Nama 			: Adriana Anggita Daeli 
 * Tanggal			: 26 Juli 2021
 * Compiler			: Dev-C++
 * ==============================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

#ifndef bintree_H
#define bintree_H

typedef struct tNodeTree *nodeT;	
typedef struct tNodeTree {
	double value;               // Menyimpan nilai operator or operand
    bool isDigit;               // Pembeda operand dan operator
	nodeT left, right;          // Anak kanan kiri
}NodeTree;

nodeT CreateNodeTree(double value, bool isDigit);
/* Konstruktor node tree dan memberi value pada node tree */
/* IS : Node tree sembarang */
/* FS : Menghasilkan sebuah node tree dengan value */

nodeT TreeInsert(nodeT root, double newValue, bool isDigit);
/* Memasukkan atau membuat node tree*/
/* IS : Root mungkin saja kosong */
/* FS : Root menjadi bagian dari tree dengan value newValue & isDigit */

void PrintTree (nodeT root);
/* Menampilkan susunan tree */
/* IS : Root terdefinisi */
/* FS : Semua simpul root tertampilkan pada layar */

double TreeCalculate(nodeT root);
/* Mengkalkulasikan expression tree */
/* IS : - */
/* FS : Mengembalikan nilai kalkulasi berupa double */
/* Referensi : https://tutorialspoint.dev/data-structure/binary-tree-data-structure/evaluation-of-expression-tree */
/* Dimodifikasi oleh : Adriana Anggita Daeli */

#endif
