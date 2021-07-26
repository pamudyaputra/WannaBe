#include <string.h>
#include <stdbool.h>
#include "list.h"
#include "utils.h"

#ifndef postfix_H
#define postfix_H

typedef struct tNodeStack *nodeS;	// alias address
typedef struct tNodeStack {
	int *array;                     // nilai operator
    int top;                        // penanda top
}NodeStack;

/*********** PROTOTYPE ****************/
/* Membuat node binary tree */
nodeS CreateNodeStack(int length);

/* Memeriksa apakah stack kosong atau tidak */
bool StackIsEmpty(nodeS stack);

/* Mengembalikan nilai stack di top */
char StackGet(nodeS stack);

/* Memproses Ekspresion Tree */
void StackPush(nodeS stack, char op);

/* Meng-pop node top */
char StackPop(nodeS stack);

/* Menentuka precedence operator */
int GetPrecendence(char ch);

/* Mengkonversi notasi infix ke notasi postfix */
int InfixToPostfix(char *infix, char *postfix);

#endif
