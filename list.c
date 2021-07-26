#include "list.h"

#ifndef list_C
#define list_C

/*********** PROTOTYPE ****************/
/* Membuat node list */
nodeL CreateNodeList (char word[]) 
{  
    // Cek string
    if (word == NULL) {
        return NULL;
    }

    // Alokasi node
    nodeL newNode = (nodeL)malloc(sizeof(NodeList));

    // Memasukkan string
    strcpy(newNode->string, word);
    newNode->next = NULL;
    
    return newNode;
}

/* Memindahkan sebuah string kedalam list node*/
void ListPush (nodeL *list, char word[]) 
{
    nodeL newNode;
    nodeL currentNode;

    // Alokasi
    newNode = CreateNodeList(word);
    
    // Masukkan list yang akan diisi ke dalam temp var
    currentNode = *list;
	
    // Kalau list kosong
    if (*list == NULL) {
        *list = newNode;
        return;
    }
    
    // Kalau list sudah berisi
    while (currentNode->next != NULL) {
        currentNode = currentNode->next;    // bergerak menuju node yg blm diisi
    }
    currentNode->next = newNode;
    
}

/* Print list */
void PrintList (nodeL list) 
{
    if (list == NULL) {
        printf("List Empty.\n");
    }
    else {
        printf("Item from the list: \n");
        while (list != NULL) {
            printf("    %s\n", list->string);
            list = list->next;
        }
    }
    printf("\n");
}

#endif
