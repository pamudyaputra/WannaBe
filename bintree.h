#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

#ifndef bintree_H
#define bintree_H

typedef struct tNodeTree *nodeT;	// alias address
typedef struct tNodeTree {
	double value;                  // nilai operator or operand
    bool isNumber;              // pembeda operand dan operator
	nodeT left, right;          // anak kanan kiri
}NodeTree;

/*********** PROTOTYPE ****************/
/* Membuat node binary tree */
nodeT CreateNodeTree(double value, bool isNumber);

/* Memasukkan karakter kepada tree */
nodeT TreeInsert(nodeT root, double newValue, bool isNumber);

/* Menampilakn susunan tree */
void PrintTree (nodeT root);

/* Memproses Ekspresion Tree */
double TreeCalculate(nodeT root);

#endif
