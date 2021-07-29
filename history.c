#include "history.h"

int width,height;

char stdHead[5][151] = {
"{====================================================================================================================================================}",
"|                                                            Calculator Standard History                                                             |",
"<===================&====================================&======================================================================&====================>",
"|     Date Time     |          Infix Expression          |                          Tree Expression                             |       Result       |",
"<===================#====================================#======================================================================#====================>"
};

char stdSpace[151] = {
"|                   |                                    |                                                                      |                    |"
};

char stdFoot[3][151] = {
"<===================%====================================%======================================================================%====================>",
"|  Press any key to go back...                                                                                                                       |",
"@====================================================================================================================================================~"
};

char progHead[5][151] = {
"{====================================================================================================================================================}",
"|                                                            Calculator Program History                                                              |",
"<===================&===============================================================&================================================================>",
"|     Date Time     |                             Input                             |                              Output                            |",
"<===================#===============================================================#================================================================>"
};

char progSpace[151] = {
"|                   |                                                               |                                                                |"
};

char progFoot[3][151] = {
"<===================%===============================================================%================================================================>",
"|  Press any key to go back...                                                                                                                       |",
"@====================================================================================================================================================~"
};

char history[10][62] = {
"{============================================================}",
"|                   Calculator History                       |",
"<============================================================>",
"|                                                            |",
"|  1. Standar Calculator History                             |",
"|  2. Programming Calculator History                         |",
"|                                                            |",
"<============================================================>",
"|  Your choice ['0' to go back to menu] : [ ][ENTER]         |",
"@============================================================~"
};

void writeCalStd(char *infix, char* tree, double res){
	FILE *fptr;
	stdHistory std;
	time_t t;
	struct tm* tm_info;
	int intl, intr, i;
	int r=0;
	char num[MAX_STR];
	
	t = time(NULL);
	tm_info = localtime(&t);
	
	strcpy(std.infix, infix);
	strcpy(std.tree, tree);
	
	intl = (int)res;
	res -= intl; res *= 100;
	intr = (int)res;
	
	memset(std.result,0,MAX_STR);
	itoa(intl,num,10);
    for(i = 0; i < strlen(num); i++)
   		std.result[r++] = num[i];
    std.result[r++] = '.';
    itoa(intr,num,10);
    if(intr == 0){
       	for(i = 0; i < 2; i++)
       		std.result[r++] = '0';
	} else {
		for(i = 0; i < 2; i++)
       		std.result[r++] = num[i];
	}
	
	strftime(std.date, sizeof(std.date), "%d/%m/%Y", tm_info);
	strftime(std.time, sizeof(std.time), "%H:%M:%S", tm_info);
	
	fptr = fopen("StdHistory.txt", "ab");
	fprintf(fptr, "%s %s %s %s %s\n",std.date,std.time,std.infix,std.tree,std.result);
	fclose(fptr);
	
}

void writeCalProg(progHistory prog){
	FILE *fptr;
	time_t t;
	struct tm* tm_info;
	
	t = time(NULL);
	tm_info = localtime(&t);
	
	strftime(prog.date, sizeof(prog.date), "%d/%m/%Y", tm_info);
	strftime(prog.time, sizeof(prog.time), "%H:%M:%S", tm_info);
	
	fptr = fopen("ProgHistory.txt", "ab");
	fprintf(fptr, "%s %s %s %s %s %s %c\n",prog.date,prog.time,prog.dec,prog.bin,prog.oct,prog.hex,prog.from);
}

void showStdHist(){
	FILE *fptr;			// File stream pointer
	stdHistory hist;	// History contents
	int i=1, j=1, l=0;	// Iterator
	int count=0;		// Line counter
	int record=0;		// Record counter
	
	// Open History File
	fptr = fopen("StdHistory.txt", "rb");
	
	width = getWidth();
	height = getHeight();
	
	// Count records
	while(!feof(fptr)){
		fscanf(fptr, "%s %s %s %s %s\n", &hist.date,&hist.time,&hist.infix,&hist.tree,&hist.result);
		record++;
		count++;
	}
	
	// Rewind file pointer from start
	rewind(fptr);
	
	// Skip file scan until last 10 records
	while(record > 10){
		fscanf(fptr, "%s %s %s %s %s\n", &hist.date,&hist.time,&hist.infix,&hist.tree,&hist.result);
		record--;
		count--;
	}
	
	// Print Header
	for(i=0;i<5;i++){
		gotoxy(width/2-75,height/2-3-(count/2)+i);
		l++;
		for(j=0;j<151;j++)
			replace(stdHead[i][j]);
	}
	
	l /= 2;
	
	// Print History Contents
	while(!feof(fptr)){
		// Print Border
		gotoxy(width/2-75,height/2-(count/2)+l);
		for(j=0;j<151;j++)
			replace(stdSpace[j]);
			
		// Scan file
		fscanf(fptr, "%s %s %s %s %s\n",&hist.date,&hist.time,&hist.infix,&hist.tree,&hist.result);
		// Print Date & Time
		gotoxy(width/2-75+1,height/2-(count/2)+l);
		printf("%s %s", hist.date, hist.time);
		// Print Infix Expression
		gotoxy(width/2-75+21,height/2-(count/2)+l);
		printf(" %s", hist.infix);
		// Print Tree Expression
		gotoxy(width/2-75+58,height/2-(count/2)+l);
		printf(" %s",hist.tree);
		// Print Result
		gotoxy(width/2-75+129,height/2-(count/2)+l);
		printf(" %s",hist.result);
		l++;
	}
	
	// Print Footer
	for(i = 0; i < 3; i++){
		gotoxy(width/2-75,height/2-(count/2)+l++);
		for(j = 0; j < 151; j++){
			replace(stdFoot[i][j]);
		}
	}
	
	// Close file
	fclose(fptr);
}

void showProgHist(){
		FILE *fptr;			// File stream pointer
	progHistory hist;	// History contents
	int i, j, l=0;		// Iterator
	int count = 0;		// Line counter
	int record = 0;		// Record counter
	
	// Open History File
	fptr = fopen("ProgHistory.txt", "rb");
	
	width = getWidth();
	height = getHeight();
	
	// Count records
	while(!feof(fptr)){
		fscanf(fptr, "%s %s %s %s %s %s %c\n",&hist.date,&hist.time,&hist.dec,&hist.bin,&hist.oct,&hist.hex,&hist.from);
		record++;
		count += 4;
	}
	
	// Rewind file pointer from start
	rewind(fptr);
	
	// Skip file scan until last 5 records
	while(record > 5){
		fscanf(fptr, "%s %s %s %s %s %s %c\n",&hist.date,&hist.time,&hist.dec,&hist.bin,&hist.oct,&hist.hex,&hist.from);
		record--;
		count -= 4;
	}
	
	// Print Header
	for(i = 0; i < 5; i++){
		gotoxy(width/2-75,height/2-3-(count/2)+i);
		l++;
		for(j = 0; j < 151; j++)
			replace(progHead[i][j]);
	}
	
	l /= 2;
	
	// Print History Contents
	while(!feof(fptr)){
		// Scan file
		fscanf(fptr, "%s %s %s %s %s %s %c\n",&hist.date,&hist.time,&hist.dec,&hist.bin,&hist.oct,&hist.hex,&hist.from);
		
		switch(hist.from){
			case '1':	// From Decimal
				// Print Binary
				gotoxy(width/2-75,height/2-(count/2)+l);
				for(i = 0; i < 151; i++)
					replace(progSpace[i]);
				gotoxy(width/2-75+85,height/2-(count/2)+l++);
				printf(" Binary      : %s", hist.bin);
				
				// Print Date & Time, Decimal, and Octadecimal
				gotoxy(width/2-75,height/2-(count/2)+l);
				for(i = 0; i < 151; i++)
					replace(progSpace[i]);
				gotoxy(width/2-75+1,height/2-(count/2)+l);
				printf("%s %s",hist.date,hist.time);
				gotoxy(width/2-75+21,height/2-(count/2)+l);
				printf(" Decimal : %s",hist.dec);
				gotoxy(width/2-75+85,height/2-(count/2)+l++);
				printf(" Octadecimal : %s", hist.oct);
				
				// Print Hexadecimal
				gotoxy(width/2-75,height/2-(count/2)+l);
				for(i = 0; i < 151; i++)
					replace(progSpace[i]);
				gotoxy(width/2-75+85,height/2-(count/2)+l++);
				printf(" Hexadecimal : %s", hist.hex);
				
				break;
			case '2':	// From Binary
				// Print Decimal
				gotoxy(width/2-75,height/2-(count/2)+l);
				for(i = 0; i < 151; i++)
					replace(progSpace[i]);
				gotoxy(width/2-75+85,height/2-(count/2)+l++);
				printf(" Decimal     : %s", hist.dec);
				
				// Print Date & Time, Binary, and Octadecimal
				gotoxy(width/2-75,height/2-(count/2)+l);
				for(i = 0; i < 151; i++)
					replace(progSpace[i]);
				gotoxy(width/2-75+1,height/2-(count/2)+l);
				printf("%s %s",hist.date,hist.time);
				gotoxy(width/2-75+21,height/2-(count/2)+l);
				printf(" Binary : %s",hist.bin);
				gotoxy(width/2-75+85,height/2-(count/2)+l++);
				printf(" Octadecimal : %s", hist.oct);
				
				// Print Hexadecimal
				gotoxy(width/2-75,height/2-(count/2)+l);
				for(i = 0; i < 151; i++)
					replace(progSpace[i]);
				gotoxy(width/2-75+85,height/2-(count/2)+l++);
				printf(" Hexadecimal : %s", hist.hex);
				
				break;
			case '3':	// From Octadecimal
				// Print Decimal
				gotoxy(width/2-75,height/2-(count/2)+l);
				for(i = 0; i < 151; i++)
					replace(progSpace[i]);
				gotoxy(width/2-75+85,height/2-(count/2)+l++);
				printf(" Decimal     : %s", hist.dec);
				
				// Print Date & Time,  Octadecimal, and Binary
				gotoxy(width/2-75,height/2-(count/2)+l);
				for(i = 0; i < 151; i++)
					replace(progSpace[i]);
				gotoxy(width/2-75+1,height/2-(count/2)+l);
				printf("%s %s",hist.date,hist.time);
				gotoxy(width/2-75+21,height/2-(count/2)+l);
				printf(" Octadecimal : %s",hist.oct);
				gotoxy(width/2-75+85,height/2-(count/2)+l++);
				printf(" Binary      : %s", hist.bin);
				
				// Print Hexadecimal
				gotoxy(width/2-75,height/2-(count/2)+l);
				for(i = 0; i < 151; i++)
					replace(progSpace[i]);
				gotoxy(width/2-75+85,height/2-(count/2)+l++);
				printf(" Hexadecimal : %s", hist.hex);
				
				break;
			case '4':	// From Hexadecimal
				// Print Decimal
				gotoxy(width/2-75,height/2-(count/2)+l);
				for(i = 0; i < 151; i++)
					replace(progSpace[i]);
				gotoxy(width/2-75+85,height/2-(count/2)+l++);
				printf(" Decimal     : %s", hist.dec);
				
				// Print Date & Time, Hexadecimal, and Binary
				gotoxy(width/2-75,height/2-(count/2)+l);
				for(i = 0; i < 151; i++)
					replace(progSpace[i]);
				gotoxy(width/2-75+1,height/2-(count/2)+l);
				printf("%s %s",hist.date,hist.time);
				gotoxy(width/2-75+21,height/2-(count/2)+l);
				printf(" Hexadecimal : %s",hist.hex);
				gotoxy(width/2-75+85,height/2-(count/2)+l++);
				printf(" Binary      : %s", hist.bin);
				
				// Print Octadecimal
				gotoxy(width/2-75,height/2-(count/2)+l);
				for(i = 0; i < 151; i++)
					replace(progSpace[i]);
				gotoxy(width/2-75+85,height/2-(count/2)+l++);
				printf(" Octadecimal : %s", hist.oct);
				
				break;
		}
		// Print Border
		gotoxy(width/2-75,height/2-(count/2)+l++);
		for(i = 0; i < 151; i++)
			replace(progSpace[i]);
	}
	
	l--;
	
	// Print Footer
	for(i = 0; i < 3; i++){
		gotoxy(width/2-75,height/2-(count/2)+l++);
		for(j = 0; j < 151; j++){
			replace(progFoot[i][j]);
		}
	}
	
	fclose(fptr);	// Close file
}

void showHistMenu(){
	int i,j;
	
	width = getWidth();
	height = getHeight();
	
	for(i = 0; i < 10; i++){
		gotoxy(width/2-31,height/2-5+i);
		for(j = 0; j < 62; j++){
			replace(history[i][j]);
		}
	}
}

void History(){
	int choice;
	
	while(1){
		system("cls");
		showHistMenu();
		gotoxy(width/2-31+43,height/2-5+8); scanf("%d", &choice);
		
		if(choice == 0)
			return;
		
		system("cls");
		switch(choice){
			case 1:
				showStdHist(); break;
			case 2:
				showProgHist(); break;
			default:
				gotoxy(width/2-31+1,height/2-5+8);								 
				printf("                                                         ");
				gotoxy(width/2-31+1,height/2-5+8);
				printf("  Invalid Input! Please input again...");
		}
		getch();
	}
}
