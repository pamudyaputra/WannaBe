#include "bintree.h"

#ifndef bintree_C
#define bintree_C

/*********** PROTOTYPE ****************/
/* Membuat node binary tree */
nodeT CreateNodeTree(double value, bool isNumber) 
{
	// Alokasi node
	nodeT newNode = (nodeT)malloc(sizeof(NodeTree));

	//Memasukkan value dkk
	newNode->isNumber = isNumber;
	newNode->value = value;
	newNode->right = NULL;
	newNode->left = NULL;

	return newNode;
}

/* Memasukkan karakter kepada tree */
nodeT TreeInsert(nodeT root, double newValue, bool isNumber)
{
    // Jika sampai di root kosong
    if (root == NULL) {
        return CreateNodeTree(newValue, isNumber);
    }

    //Jika root tidak kosong, anak kanan kosong atau root kanan bukan operand
    if (root->right == NULL || !root->right->isNumber) {
        nodeT temp = TreeInsert(root->right, newValue, isNumber);
        if (temp != NULL) {
            root->right = temp;
            return root;
        }
    }

    //Jika root tidak kosong, anak kiri kosong
    if (root->value != '-' && root->value != '$' && (root->left == NULL || !root->left->isNumber)) {
        nodeT temp = TreeInsert(root->left, newValue, isNumber);
        if (temp != NULL) {
            root->left = temp;
            return root;
        }
    }
  return NULL;
}

/* Menampilakn susunan tree */
void PrintTree (nodeT root) 
{
    if (root != NULL) {
        if (root->isNumber) {
            printf("%.2lf", root->value);
        } else {
            printf("%c", (int)root->value);
        }
        printf(" (");
        PrintTree(root->left);
        PrintTree(root->right);
        printf(") ");
    }
}

/* Memproses Ekspresion Tree */
double TreeCalculate(nodeT root) 
{
    // Hanya angka saja
	if (root->isNumber) {
    	return root->value;
	}
	
	// Rekursif kanan
    double rightOp = TreeCalculate(root->right);
    
    // Memproses UNARY OPERATOR
    if (root->value == '-') {
		return rightOp * -1;
	}
	if (root->value == '$') {
		return sqrt(rightOp);
	}
	
    // Rekursif kiri
    double  leftOp = TreeCalculate(root->left);
	
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
