#include "bintree.h"

#ifndef bintree_C
#define bintree_C

int t = 0;

/* Body fucntion / procedure */
nodeT CreateNodeTree(double value, bool isDigit) 
{
	/* Konstruktor node tree dan memberi value pada node tree */
	/* IS : Node tree sembarang */
	/* FS : Menghasilkan sebuah node tree dengan value */	
	
	/* Kamus Data */
	nodeT newNode;
	
	/* Algoritma */
	// Alokasi node
	newNode = (nodeT)malloc(sizeof(NodeTree));

	//Memasukkan value dkk
	newNode->isDigit = isDigit;
	newNode->value = value;
	newNode->right = NULL;
	newNode->left = NULL;

	return newNode;
}

nodeT TreeInsert(nodeT root, double newValue, bool isDigit)
{
	/* Memasukkan atau membuat node tree*/
	/* IS : Root mungkin saja kosong */
	/* FS : Root menjadi bagian dari tree dengan value newValue & isDigit */
	
	/* Kamus Data */
	nodeT temp;
	
	/* Algoritma */
    // Jika sampai di root kosong
    if (root == NULL) {
        return CreateNodeTree(newValue, isDigit);
    }

    //Jika root tidak kosong, anak kanan kosong atau root kanan bukan operand
    if (root->right == NULL || !root->right->isDigit) {
        temp = TreeInsert(root->right, newValue, isDigit);
        if (temp != NULL) {
            root->right = temp;
            return root;
        }
    }

    //Jika root tidak kosong, anak kiri kosong
    if (root->value != '-' && root->value != '$' && (root->left == NULL || !root->left->isDigit)) {
        temp = TreeInsert(root->left, newValue, isDigit);
        if (temp != NULL) {
            root->left = temp;
            return root;
        }
    }
  return NULL;
}

/* Menampilakn susunan tree */
void PrintTree (nodeT root, char* hist) 
{
	/* Menampilakn susunan tree */
	/* IS : Root terdefinisi */
	/* FS : Semua simpul root tertampilkan pada layar */
	
	/* Kamus Data */
	double dob = 0;
	int intl = 0;
	int intr = 0;
	int i = 0;
	char num[MAX_STR];
	
	/* Algoritma */
	memset(num,0,MAX_STR);
    if (root != NULL) {
        if (root->isDigit) {
            printf("%.2lf", root->value);
            
            dob = root->value;
            intl = (int)dob;
            dob -= intl; dob *= 100;
            intr = (int)dob;
            itoa(intl,num,10);
            for(i = 0; i < strlen(num); i++)
            	hist[t++] = num[i];
            hist[t++] = '.';
            itoa(intr,num,10);
            if(intr == 0){
            	for(i = 0; i < 2; i++)
            		hist[t++] = '0';
			} else {
				for(i = 0; i < 2; i++)
            		hist[t++] = num[i];
			}
        } else {
            printf("%c", (int)root->value);
            hist[t++] = (char)root->value;
        }
        printf("(");
        hist[t++] = '(';
        PrintTree(root->left, hist);
        PrintTree(root->right, hist);
        printf(")");
        hist[t++] = ')';
    }
}

/* Memproses Ekspresion Tree */
double TreeCalculate(nodeT root) 
{
	/* Mengkalkulasikan expression tree */
	/* IS : - */
	/* FS : Mengembalikan nilai kalkulasi berupa double */
	
	/* Kamus Data */
	double rightOp, leftOp;
	
	/* Algoritma */
    // Hanya angka saja
	if (root->isDigit) {
    	return root->value;
	}
	
	// Rekursif kanan
    rightOp = TreeCalculate(root->right);
    
    // Memproses UNARY OPERATOR
    if (root->value == '-') {
		return rightOp * -1;
	}
	if (root->value == '$') {
		return sqrt(rightOp);
	}
	
    // Rekursif kiri
    leftOp = TreeCalculate(root->left);
	
    // Memroses BINARY OPERATOR
    switch ((int)(root->value)) {
		case '+':
	return leftOp + rightOp;
		case '*':
	return leftOp * rightOp;
		case '/':
	return leftOp / rightOp;
		case '^':
	return pow(leftOp, rightOp);
	}
}

#endif
