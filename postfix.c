#include "postfix.h"


#ifndef postfix_C
#define postfix_C

/*********** PROTOTYPE ****************/
/* Membuat node binary tree */
nodeS CreateNodeStack(int length) 
{
    nodeS stack;
    
    // Alokasi node
    stack = (nodeS)malloc(sizeof(NodeStack));
    
    // Alokasi value array
    stack->array = (int *)malloc(length * sizeof(int));

    // Mengisi value top
    stack->top = -1;

    return stack;
}

/* Memeriksa apakah stack kosong atau tidak */
bool StackIsEmpty(nodeS stack)
{
    return stack->top == -1;
}

/* Mengembalikan nilai stack di top */
char StackGet(nodeS stack) 
{
    return stack->array[stack->top];
}

/* Memproses Ekspresion Tree */
void StackPush(nodeS stack, char op)
{
    stack->array[++stack->top] = op;
}

/* Meng-pop node top */
char StackPop(nodeS stack) 
{
    if (StackIsEmpty(stack)) {
        return '\0';
    }
    return stack->array[stack->top--];
}

/* Menentuka precedence operator */
int GetPrecendence(char ch) 
{
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

/* Mengkonversi notasi infix ke notasi postfix */
int InfixToPostfix(char *infix, char *postfix)
{
    nodeS stack;
    int i, j;
    bool unaryStart = *infix == '-' || *infix == '$';
    
    // Alokasi utk stack
    stack = CreateNodeStack(strlen(infix));
    
    // Cek karakter tiap node
    for (i = 0, j = 0; infix[i]; i++) {
		
        // Spasi
        if (infix[i] == ' ') {
	      	continue;
	    } 

        // Operand
        else if (isNumeric(infix[i]) || infix[i] == '.') {
            do {
                postfix[j++] = infix[i++];
                
            } while (isNumeric(infix[i]) || infix[i] == '.');
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
            if (infix[i] == '-' && isNumeric(infix[i-1])) {
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
