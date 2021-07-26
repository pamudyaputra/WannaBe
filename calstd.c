#include "calstd.h"

#ifndef calstd_C
#define calstc_C

nodeL infixExpressions = NULL;
nodeL postfixExpressions = NULL;

int CalStandard()
{
	system ("cls");
	int i = 0, counter = 0;
	int cek = 0;

	while (true) {
	    char infix[MAX_STR], postfix[MAX_STR];
	    printf("Type an arithmetic expression ('0' to stop): ");
	    gets(infix);
	    if (strcmp(infix, "0") == 0) {
	      break;
	    }
	    InfixToPostfix(infix, postfix);
	    
	    ListPush(&infixExpressions, infix);
	    ListPush(&postfixExpressions, postfix);
  		printf("\n");
	    printf("Expression #%i\n", i + 1);
	    printf("    Infix:   %s\n", infixExpressions->string);
	    printf("    Postfix: %s\n", postfixExpressions->string);
	    printf("    Tree:    ");
	    nodeT tree = BuildTreeInterface(postfixExpressions->string);
	    PrintTree(tree);
	    printf("\n    Result:  ");
        printf("%.2lf", TreeCalculate(tree));
	    printf("\n");
	
	    infixExpressions = infixExpressions->next;
	    postfixExpressions = postfixExpressions->next;
	
		printf("\n");
		system("pause");
		printf("\n");
	}

  return 0;
}

/* Memeriksa karakter yang akan dimasukkan ke dalam tree */
nodeT BuildTreeInterface(char *expression) 
{
    nodeT tree = NULL;
    int i, len, index;

    // Ambil panjang expression
    len = strlen(expression);

    // Cek
    for (i = len - 1; i >= 0; i--) {
        // Spasi
        if (expression[i] == ' ') {
      		continue;
   		}

        // Operand
        if (isNumeric(expression[i]) || expression[i] == '.') {
            char number[MAX_STR];
            index = 0;
            do {
                number[index++] = expression[i--];
            } while ((i >= 0 && isNumeric(expression[i])) || expression[i] == '.');
            number [index] = '\0';

            // String to double
            double temp = strtod(strrev(number), NULL); 
            // Masuk dalam tree
            tree = TreeInsert(tree, temp, true);
        }

        // Operator
        else {
        	// Masuk dalam tree
            tree = TreeInsert(tree, expression[i], false);
        }
        
    }
    return tree;
}

#endif
