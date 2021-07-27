/* 
 * Program 			: calstd.c
 * Deskripsi 		: Body list berkait dgn kalkulator standard
 * Nama 			: Adriana Anggita Daeli 
 * Tanggal			: 26 Juli 2021
 * Compiler			: Dev-C++
 * ==============================================================
 */

#include "calstd.h"

#ifndef calstd_C
#define calstc_C

/* Kamus Data */
int i, j, width, height;
bool valid;

/* Body fucntion / procedure */
int CalStd()
{
	/* Kamus Data */
	int counter = 0;
	int cek = 0;
	char infix[MAX_STR], postfix[MAX_STR];
	nodeL infixExpressions = NULL;
	nodeL postfixExpressions = NULL;
	nodeT tree;
	
	/* Algoritma */
	width = getWidth();
	height = getHeight();
	i = 0;
	
	while (true) {
		// Print map for calculator standard
		system ("cls");
		mapCalStd();
		
		// Scan user input
	    gotoxy(width/2-45+3, height/2-8+3); gets(infix);
	    if (strcmp(infix, "0") == 0) {
	      break;
	    }
	    
	    if (ValidChar(infix) && ValidParenthesized(infix) && ValidOp(infix)){
	    	 // Konversi notasi and masukkan ke list
		    InfixToPostfix(infix, postfix);
		    ListPush(&infixExpressions, infix);
		    ListPush(&postfixExpressions, postfix);
	  		
	  		// Print notasi infix
			gotoxy(width/2-45+23, height/2-8+6);
		    printf("%s", infixExpressions->string);
		    
		    // Print notasi postfix
		    gotoxy(width/2-45+23, height/2-8+8);
		    printf("%s", postfixExpressions->string);
		    
		    // Buat pohon and print
		    tree = BuildTreeInterface(postfixExpressions->string);
		    gotoxy(width/2-45+23, height/2-8+10);
			PrintTree(tree);
			
			// Print kalkulasi pohon
			gotoxy(width/2-45+23, height/2-8+12);
	        printf("%.2lf", TreeCalculate(tree));
			
			// Move to next node of list (new calculate)
		    infixExpressions = infixExpressions->next;
		    postfixExpressions = postfixExpressions->next;
		
			gotoxy(width/2-45+2, height/2-8+15); printf("Press any key to calculate... "); getch();
		} else {
			gotoxy(width/2-45+2, height/2-8+15); printf("Expression invalid! Press any key to calculate... "); getch();
	 }
	    
	   
	}

  return 0;
}

nodeT BuildTreeInterface(char *op) 
{	
	/* Pemilah karakter operator atau operand dan memprosesnya */
	/* karakter operand terlebih dahulu sebelum dimasukkan ke dalam tree */
	/* I.S. : Pohon belum terkalkulasi */
	/* F.S. : Mengembalikan hasil kalkulasi */
	
	/* Kamus Data */
    nodeT tree = NULL;
    int i, len, index;
    char number[MAX_STR];
    double temp;

    // Ambil panjang op
    len = strlen(op);

    // Cek
    for (i = len - 1; i >= 0; i--) {
        // Spasi
        if (op[i] == ' ') {
      		continue;
   		}

        // Operand
        if (isdigit(op[i]) || op[i] == '.') {
            index = 0;
            do {
                number[index++] = op[i--];
            } while ((i >= 0 && isdigit(op[i])) || op[i] == '.');
            number [index] = '\0';

            // String to double
            temp = strtod(strrev(number), NULL); 
            // Masuk dalam tree
            tree = TreeInsert(tree, temp, true);
        }

        // Operator
        else {
        	// Masuk dalam tree
            tree = TreeInsert(tree, op[i], false);
        }
        
    }
    return tree;
}


bool ValidParenthesized(char *op) 
{
	/* Memilah operator parenthesis yang tidak valid */
	
	/* Kamus Data */
	char temp[MAX_STR];
	int top = -1;
	
	/* Algoritma */
	for (i = 0; op[i] != '\0'; i++) {
		if (op[i] == '(') {
			temp[top] = op[i];
			top++;
		}
		else if (op[i] == ')') {
			if (top == -1) {
				return false;
			}
			else {
				top--;
			}
		}
	}
	if(top == -1) 
		return true;
	else
		return false;
}
 
 bool ValidChar(char *op) 
 {
 	/* Pemilah karakter yang tidak valid*/
	
	/* Kamus Data */

	/* Algoritma */
	for (i = 0; op[i]; i++) {
		// Char tidak sesuai dengan guide
		if (isalpha(op[i]) && op[i] != '(' && op[i] != ')' && op[i] != '+' && op[i] != '-' && op[i] != '*' &&
			op[i] != '/' && op[i] != '$' && op[i] != '.' && op[i] != '^' && op[i] != ' ') {
				return false;
		} 
	}
	return true;
 }
 
 bool ValidOp(char *op)
 {
 	/* Mengecek operasi yang tidak valid*/
	
	/* Kamus data */
	
	/* Algoritma */
	for (i = 0; op[i]; i++) {
		
		// Spasi lebih dari 1 karakter INVALID
		if (op[i] == ' ') {
			if (op[i+2] == ' ') {
				return false;
			}
		}	
		
		// Titik
		if (op[i] == '.' && !isdigit(op[i+1])) 
			return false;
	
		if (op[i] == '.' && !isdigit(op[i-1])) 
			return false;
		
		// Operator + - * / ^
		if (op[i] == '+' || op[i] == '-' || op[i] == '*' || op[i] == '/' || op[i] == '^') {
			// cek belakang
			if (op[i-1] == ' ') {
				if (!isdigit(op[i-2]) || op[i-2] == '+' || op[i-2] == '-' || 
					op[i-2] == '*' || op[i-2] == '/' || op[i-2] == '^') {
					return false;
				}
			} 
			if (op[i-1] != ' ') {
				if (!isdigit(op[i-1]) || op[i-1] == '+' || op[i-1] == '-' || 
					op[i-1] == '*' || op[i-1] == '/' || op[i-1] == '^') {
					return false;
				} 
			}
			// cek depan
			if (op[i+1] == ' ') {
				if (!isdigit(op[i+2]) ||  op[i+2] == '+' || op[i+2] == '-' || 	
					op[i+2] == '*' || op[i+2] == '/' || op[i+2] == '^' ){				
					if (op[i+2] != '$') {
						return false;
					}
				} 
			} 
			if (op[i+1] != ' ') {
				if (!isdigit(op[i+1]) || op[i+1] == '+' || op[i+1] == '-' || 
					op[i+1] == '*' || op[i+1] == '/' || op[i+1] == '^') {
					if (op[i+1] != '$') {
						return false;
					}
				} 
			}
		}
		// Operator $
		if (op[i] == '$') {
			// cek belakang
			if (op[i-1] == ' ') {
				if (isdigit(op[i-2]) || op[i-2] == ')') {
					return false;
				}
			} else if (isdigit(op[i-1]) || op[i-1] == ')') {
				return false;
			}
			// cek depan
			if (op[i+1] == ' ') {
				if (!isdigit(op[i+2]) || op[i+2] == '(' ) {
					return false;
				} 
			} else if (!isdigit(op[i+1]) || op[i+1] == ')' ) {
				return false;
			} 
		}	
	}
	return true;
 }
#endif
