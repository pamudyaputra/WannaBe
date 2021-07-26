#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef list_H
#define list_H

#define MAX_STR 100

typedef struct tNodeList *nodeL;	// alias address
typedef struct tNodeList {
	char string [MAX_STR];
	nodeL next;
}NodeList;

/*********** PROTOTYPE ****************/
/* Membuat node list */
nodeL CreateNodeList (char word[]);

/* Memindahkan sebuah string kedalam list node*/
void ListPush (nodeL *list, char word[]);

/* Print list */
void PrintList (nodeL list);

#endif