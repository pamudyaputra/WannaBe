/* 
 * Program 			: main.c
 * Deskripsi 		: Program utama
 * Nama 			: Adriana Anggita Daeli 
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
#include "map.h"

int main() {
	int choice;
	screenMode();
	
	do {
		system("cls");
		mapMenu(&choice);
		
		int	width = getWidth();
		int	height = getHeight();
		
		int x = width / 2 - 6;
		int y = height / 2 + 8;
	
		gotoxy(x, y); scanf("%d", &choice); getchar();
		
		switch(choice) {
			case 1 :
				CalStandard();
				break;
			case 2 :
				CalProg();
				break;
			case 3 :
//				History();
			case 4 :
//				Help();
			case 5 :
//				Credit();
			case 0 :
				exit(EXIT_SUCCESS);
			
		}
	
	} while (choice != 0);
	return 0;
}
