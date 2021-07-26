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
		
		int	width = (int)getWidth();
		int	height = (int)getHeight();
		
		int x = width / 2 - 6;
		int y = height / 2 + 8;
	
		gotoxy(x, y); scanf("%d", &choice); getchar();
		
		switch(choice) {
			case 1 :
				CalStandard();
				break;
			case 2 :
				CalProgram();
			case 3 :
			case 4 :
			case 5 :
			case 0 :
				exit(EXIT_SUCCESS);
			
		}
	
	} while (choice != 0);
	return 0;
}
