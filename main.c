/* 
 * Program 			: main.c
 * Deskripsi 		: Program utama
 * Nama 			: Punya gita aja
 * Tanggal			: 26 Juli 2021
 * Compiler			: Dev-C++
 * ==============================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include "calprog.h"
#include "calstd.h"

/* Body fucntion / procedure */
void Guide();
void Credit();

/* Algoritma*/
int main() 
{
	/* Kamus Data */	
	int choice;
	screenMode();
	
	do {
		system("cls");
		mapMenu(&choice);
		
		int	width = getWidth();
		int	height = getHeight();
	
		gotoxy(width / 2 - 14, height / 2 + 9); scanf("%d", &choice); getchar();
		
		switch(choice) {
			case 1 :
				CalStd();
				break;
			case 2 :
				CalProg();
				break;
			case 3 :
				History();
				break;
			case 4 :
				Guide();
				break;
			case 5 :
				Credit();
				break;
			case 0 :
				exit(EXIT_SUCCESS);
			default:
				gotoxy(width/2-31+1,height/2-5+8);								 
				printf("                                                         ");
				gotoxy(width/2-31+1,height/2-5+14);
				printf("  Invalid Input! Please input again..."); getch();
		}
	
	} while (choice != 0);
	return 0;
}

void Guide()
{
	/* Program fitur guide */
	/* I.S. : Program belum berjalan */
	/* F.S. : Layar akan menampilkan box untuk user dan calculator guide */	
	
	/* Kamus Data */
	int choice;
	int	width = getWidth();
	int	height = getHeight();

	
	/* Algoritma */
	do {
		system("cls");
		mapGuide();
		gotoxy(width / 2 - 2, height / 2 + 10); scanf("%d", &choice); getchar();
		switch(choice) {
			case 1:
				system("cls");
				mapCalStdGuide();
				gotoxy(width / 2 - 43, height / 2 + 9); printf("Press any key to go to back... "); getch();
				break;
			case 2:
				system("cls");
				mapCalProgGuide();
				gotoxy(width / 2 - 42, height / 2 + 19); printf("Press any key to go to back... "); getch();
				break;
			case 0:
				break;
			default:
				gotoxy(width/2-31,height/2-5+15);								 
				printf("                                                         ");
				gotoxy(width/2-44,height/2-5+15);
				printf("  Invalid Input! Please input again..."); getch();
		}
	} while (choice != 0);
}

void Credit()
{
	/* Program fitur guide */
	/* I.S. : Program belum berjalan */
	/* F.S. : Layar akan menampilkan box untuk user dan calculator guide */	
	
	/* Kamus Data */
	int	width = getWidth();
	int	height = getHeight();

	/* Algoritma */
	system("cls");
	mapCredit();
	gotoxy(width / 2 - 29, height / 2 + 6); printf("Press any key to go to back... "); getch();
}
