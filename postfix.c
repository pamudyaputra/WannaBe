/* 
 * Program 			: postfix.c
 * Deskripsi 		: Body list berkait dgn rerpresentasi stack 
                      untuk proses konversi notasi infix to 
					  postfix
 * Nama 			: Adriana Anggita Daeli 
 * Tanggal			: 26 Juli 2021
 * Compiler			: Dev-C++
 * ==============================================================
 */

#include "postfix.h"

#ifndef postfix_C
#define postfix_C

/* Body fucntion / procedure */
nodeS CreateNodeStack(int length) 
{
    /* Konstruktor node stack */
	/* I.S. : Stack sembarang */
	/* F.S. : Lebar screen komputer diketahui */
	
	/* Kamus Data */
	nodeS stack;
	
	/* Algoritma */
    stack = (nodeS)malloc(sizeof(NodeStack));	// Alokasi node
    stack->array = (int *)malloc(length * sizeof(int));		// Alokasi value array
    stack->top = -1; 

    return stack;
}

bool StackIsEmpty(nodeS stack)
{
	/* Mengirim true jika stack kosong */
    return stack->top == -1;
}

char StackGet(nodeS stack) 
{
	/* Mengembalikan nilai stack di top */
    return stack->array[stack->top];
}

void StackPush(nodeS stack, char op)
{
	/* Menambahkan op sebagai elemen Stack */
	/* I.S. : Stack mungkin kosong */
	/* F.S. : op menjadi TOP yang baru, TOP bertambah 1 */
	
	/* Kamus Data */
	
	/* Algoritma */
    stack->array[++stack->top] = op;
}

char StackPop(nodeS stack) 
{
	/* Menghapus TOP dari stack*/
	/* I.S. : Stack tidak mungkin kosong */
	/* F.S. : TOP berganti menjadi elemen yang sebelumnya berada di bawah TOP */
	
	/* Kamus Data */
	
	/* Algoritma */
    if (StackIsEmpty(stack)) {
        return '\0';
    }
    return stack->array[stack->top--];
}

int GetPrecendence(char ch) 
{
	/* Mengembalikan nilai prioritas dari ch */
	
	/* Kamus Data */
	
	/* Algoritma */
    switch (ch) {
        case '+':
        case '-':
            return 1;

        case '*':
        case '/':
            return 2;

        case '^':
            return 3;

        case '$':
            return 4;

        default:
            return -1;
    }
}

int InfixToPostfix(char *infix, char *postfix)
{
	/* Mengkonversi notasi infix ke notasi postfix */
	/* I.S. : Notasi infix bisa berisi sebuah ekspresi atau tidak*/
	/* F.S. : Notasi postfix berisi hasil konversi notasi infix */
    
	/* Kamus Data */
	nodeS stack;
    int i, j;
    bool unaryStart = *infix == '-' || *infix == '$';
    
    /* Algoritma */
    // Alokasi utk stack
    stack = CreateNodeStack(strlen(infix));
    
    // Cek karakter tiap node
    for (i = 0, j = 0; infix[i]; i++) {
		
        // Spasi
        if (infix[i] == ' ') {
	      	continue;
	    } 

        // Operand
        else if (isdigit(infix[i]) || infix[i] == '.') {
            do {
                postfix[j++] = infix[i++];
                
            } while (isdigit(infix[i]) || infix[i] == '.');
            postfix[j++] = ' ';
            i--;
        }

        // Buka kurung
        else if (infix[i] == '(') {
            StackPush(stack, infix[i]);
        }

        // Tutup Kurung
        else if (infix[i] == ')') {
            // Jika stack tidak kosong dan top adalah '('
            while (!StackIsEmpty(stack) && StackGet(stack) != '(') {
                postfix[j++] = StackPop(stack);
                postfix[j++] = ' ';
            }

            if (!StackIsEmpty(stack) && StackGet(stack) != '(') {
                return -1;
            } else {
                StackPop(stack);
            }
        }

        // Operator
        else {
            // Jika stack tidak kosong dan precedence top >= dari current
            while (!StackIsEmpty(stack) && GetPrecendence(infix[i]) <= GetPrecendence(StackGet(stack))) {
                postfix[j++] = StackPop(stack);
                postfix[j++] = ' ';
            }

            // Jika operator '-'
            if (infix[i] == '-' && isdigit(infix[i-1])) {
                StackPush(stack, '+');
            }

            // Push current operator
            StackPush(stack, infix[i]);
        }
    }

    // Pop sisa operator kedalam postfix
    while (!StackIsEmpty(stack)) {
        postfix[j++] = StackPop(stack);
        postfix[j++] = ' ';
    }

    postfix[j--] = '\0';
    return 0;
}

#endif
