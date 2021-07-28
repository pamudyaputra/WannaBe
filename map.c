/* 
 * Program 			: map.c
 * Deskripsi 		: Body list berkait dgn tampilan
 * Nama 			: Adriana Anggita D, Pamudya Putra P 
 * Tanggal			: 26 Juli 2021
 * Compiler			: Dev-C++
 * ==============================================================
 */

# include "map.h"

/* Kamus data */
int i, j, width, height, x, y;

/* Body fucntion / procedure */
void screenMode() 
{
	/* Membuat cmd mode fullscreen */
	system("color e4");	   // Screen color	
		
    ShowWindow(GetConsoleWindow(), SW_SHOWMAXIMIZED); 	// Screen mode full
}

int getWidth() 
{	
	/* Mengembalikan value lebar tiap screen komputer */
	/* I.S. : - */
	/* F.S. : Lebar screen komputer diketahui */
	
	CONSOLE_SCREEN_BUFFER_INFOEX info = {0};
    HANDLE hConsole = NULL;
    
    // Get width of this window
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    info.cbSize = sizeof(info);
    GetConsoleScreenBufferInfoEx(hConsole, &info);

    width = info.srWindow.Right;
	
	return width;
}

int getHeight() 
{	
	/* Mengembalikan value tinggi tiap screen komputer */
	/* I.S. : - */
	/* F.S. : Tinggi screen komputer diketahui */

	CONSOLE_SCREEN_BUFFER_INFOEX info = {0};
    HANDLE hConsole = NULL;
	
    // Get height of this window
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    info.cbSize = sizeof(info);
    GetConsoleScreenBufferInfoEx(hConsole, &info);

    height = info.srWindow.Bottom;
    
	return height;
}

void gotoxy(int x, int y) 
{	
	/* Kursor untuk menunjuk pada titik (x,y) tertentu */	
  	COORD coord;
  	coord.X = x;
  	coord.Y = y;
  	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

char menu[20][63] = {
	"{============================================================}",
	"|               {==== {====} |     {==== {====}              |",
	"|               |     |    | |     |     |    |              |",
	"|               |     <====> |     |     |    |              |",
	"|               @==== |    | @==== @==== @====~              |",
	"|                       / Adriana Pamudya 2021/              |",
	"<============================================================>",
	"|                             MENU                           |",
	"<============================================================>",
	"|                                                            |",
	"|       1. Calculator Standard                               |",
	"|       2. Calculator Program                                |",
	"|       3. History                                           |",
	"|       4. Guide                                             |",
	"|       5. Credit                                            |",
	"|       0. Exit                                              |",
	"|                                                            |",
	"<============================================================>",
	"|  Your choice: [ ][ENTER]                                   |",
	"@============================================================~"
};

char calProgIn[15][62] = {	
	"{============================================================}",
	"|                   CALCULATOR PROGRAMMER                    |",
	"<============================================================>",
	"|                        Convert From                        |",
	"<============================================================>",
	"|                                                            |",
	"|       1. Decimal                                           |",
	"|       2. Binary                                            |",
	"|       3. Octadecimal                                       |",
	"|       4. Hexadecimal                                       |",
	"|                                                            |",
	"<============================================================>",
	"|  Your choice ['0' to go back to menu]: [ ][ENTER]          |",
	"@============================================================~"
};

char calProgOut1[16][62] = {
	"{============================================================}",
	"| Type a decimal number ['0' to go back to menu]             |",
	"| [                                                        ] |",
	"<============================================================>",
	"|                                                            |",
	"| Decimal         :                                          |",
	"|                                                            |",
	"| Binary          :                                          |",
	"|                                                            |",
	"| Octadecimal     :                                          |",
	"|                                                            |",
	"| Hexadecimal     :                                          |",
	"|                                                            |",
	"<============================================================>",
	"|                                                            |",
	"@============================================================~"
};

char calProgOut2[16][62] = {
	"{============================================================}",
	"| Type a binary number ['0' to go back to menu]              |",
	"| [                                                        ] |",
	"<============================================================>",
	"|                                                            |",
	"| Decimal         :                                          |",
	"|                                                            |",
	"| Binary          :                                          |",
	"|                                                            |",
	"| Octadecimal     :                                          |",
	"|                                                            |",
	"| Hexadecimal     :                                          |",
	"|                                                            |",
	"<============================================================>",
	"|                                                            |",
	"@============================================================~"
};

char calProgOut3[16][62] = {	
	"{============================================================}",
	"| Type an octadecimal number ['0' to go back to menu]        |",
	"| [                                                        ] |",
	"<============================================================>",
	"|                                                            |",
	"| Decimal         :                                          |",
	"|                                                            |",
	"| Binary          :                                          |",
	"|                                                            |",
	"| Octadecimal     :                                          |",
	"|                                                            |",
	"| Hexadecimal     :                                          |",
	"|                                                            |",
	"<============================================================>",
	"|                                                            |",
	"@============================================================~"
};

char calProgOut4[16][62] = {
	"{============================================================}",
	"| Type a hexadecimal number ['0' to go back to menu]         |",
	"| [                                                        ] |",
	"<============================================================>",
	"|                                                            |",
	"| Decimal         :                                          |",
	"|                                                            |",
	"| Binary          :                                          |",
	"|                                                            |",
	"| Octadecimal     :                                          |",
	"|                                                            |",
	"| Hexadecimal     :                                          |",
	"|                                                            |",
	"<============================================================>",
	"|                                                            |",
	"@============================================================~"
};

char calStd[18][93] = {
	"{==========================================================================================}",
	"|                                    CALCULATOR STANDARD                                   |",
	"<==========================================================================================>",
	"| Type an arithmatic expression ['0' to go back to menu]                                   |",
	"| [                                                                                      ] |",
	"<==========================================================================================>",
	"|                                                                                          |",
	"| Infix Expression   :                                                                     |",
	"|                                                                                          |",
	"| Postfix Expression :                                                                     |",
	"|                                                                                          |",
	"| Expression Tree    :                                                                     |",
	"|                                                                                          |",
	"| Result             :                                                                     |",
	"|                                                                                          |",
	"<==========================================================================================>",
	"|                                                                                          |",
	"@==========================================================================================~"
};

char guide[25][93] = {
	"{==========================================================================================}",
	"|                                        USER GUIDE                                        |",
	"<==========================================================================================>",
	"| This calculator has 5 features, namely:                                                  |",
	"|                                                                                          |",
    "| 1. Calculator standard, perform standard caculation                                      |",
	"|                                                                                          |",
	"| 2. Calcualtor programmer, convert decimal, binary, octadecimal, and hexadecimal numbers. |",
	"|                                                                                          |",
	"| 3. History, to view the history of calculations and conversions that have been done.     |",
	"|                                                                                          |",
	"| 4. Guide, to find out how to use CALCO application and to fint out what are the guides   |",
	"|    while using Calculator standard and Calculator Programmer                             |",
	"|                                                                                          |",
	"| 5. Credit,this feature contains information about the make of the CALCO application      |",
	"<==========================================================================================>",
	"|                                     CALCULATOR GUIDE                                     |",
 	"<==========================================================================================>",
 	"|                                                                                          |",
 	"|       1. Calculator Standard                                                             |",
 	"|       2. Calculator Programmer                                                           |",
 	"|                                                                                          |",
 	"<==========================================================================================>",
	"|  Your choice ['0' to go back to menu] : [ ][ENTER]                                       |",
	"@==========================================================================================~"
};

char calStdGuide[24][94] = {	
	"{==========================================================================================}",
	"|                                CALCULATOR STANDARD GUIDE                                 |",
	"<==========================================================================================>",
 	"| Follow these rules, otherwise the expression will be considered INVALID!                 |",
 	"|                                                                                          |",
 	"| 1. If you write an unary expressions, especially with the negation operator (-),         |",
 	"|    you must parenthesized the unary operation.                                           |",
 	"|                                                                                          |",
 	"| 2. When you write an expression, you can only write one space between characters         |",
	"|    or no spaces at all.                                                                  |",
	"|                                                                                          |",
	"| 3. Here some of the characters that are VALID for creating expressions are:              |",
	"|    '(' and ')' for parenthesized an operation.                                           |",
	"|    '$' and '^' for square root and squared operation.                                    |",
	"|    '*' and '/' for multiplied and divided operation.                                     |",
	"|    '+' and '-' for plus and minus negative operation.                                    |",
	"|    '.' for decimal point.                                                                |",
	"|                                                                                          |",
	"| 4. Make sure the parenthesis operator is balanced.                                       |",
 	"<==========================================================================================>",
	"|                                                                                          |",
	"@==========================================================================================~"
};

char calProgGuide[41][89] = {
	"{=======================================================================================}",
	"|                              CALCULATOR PROGRAMMER GUIDE                              |",
	"<===========================================&===========================================>",
	"|           Decimal Converter Guide         |        Hexadecimal Converter Guide        |",
	"<===========================================#===========================================>",
	"|                                           |                                           |",
	"| Input your basic 0 to 9 number            | Input 0 to 9 numbers and A to F           |",
	"| DO NOT INPUT CHARACTERS!                  | DO NOT INPUT OTHER THAN 0 - 8 AND A - F!  |",
	"| Examples:                                 | Examples:                                 |",
	"| 1. Input Decimal : 100                    | 1. Input Hexadecimal : 3A                 |",
	"|        Output:                            |        Output:                            |",
	"|        Binary      : 1100100              |        Decimal     : 58                   |",
	"|        Octadecimal : 144                  |        Binary      : 111010               |",
	"|        Hexadecimal : 64                   |        Octadecimal : 72                   |",
	"| 2. Input Decimal : 2312                   | 2. Input Hexadecimal : A54                |",
	"|        Output:                            |        Output:                            |",
	"|        Binary      : 100100001000         |        Decimal     : 2644                 |",
	"|        Octadecimal : 4410                 |        Binary      : 101001010100         |",
	"|        Hexadecimal : 908                  |        Octadecimal : 5124                 |",
	"|                                           |                                           |",
	"<===========================================#===========================================>",
	"|           Binary Converter Guide          |       Octadecimal Converter Guide         |",
	"<===========================================#===========================================>",
	"|                                           |                                           |",
	"| Input 0 or 1 numbers                      | Input 0 - 8 numbers                       |",
	"| DO NOT INPUT OTHER THAN 0 AND 1!          | DO NOT INPUT OTHER THAN 0 - 8!            |",
	"| Examples:                                 | Examples:                                 |",
	"| 1. Input Binary : 1100100                 | 1. Input Octadecimal : 144                |",
	"|        Output:                            |        Output:                            |",
	"|        Decimal     : 100                  |        Decimal     : 100                  |",
	"|        Octadecimal : 144                  |        Binary      : 1100100              |",
	"|        Hexadecimal : 64                   |        Hexadecimal : 64                   |",
	"| 2. Input Binary : 100100001000            | 2. Input Octadecimal : 4410               |",   
	"|        Output:                            |        Output:                            |",
	"|        Decimal     : 2312                 |        Decimal     : 2312                 |",
	"|        Octadecimal : 4410                 |        Binary      : 1001000010           |",
	"|        Hexadecimal : 908                  |        Hexadecimal : 908                  |",
	"|                                           |                                           |",
	"<===========================================%===========================================>",
	"|                                                                                       |",
	"@=======================================================================================~"
};

char credit[16][63] = {	
	"{============================================================}",
	"|                          CREDIT                            |",
	"<============================================================>",
	"|        Copyright(c)2021 CALCO.All rights reserved.         |",
	"|                                                            |",
	"|                          AUTHOR                            |",
    "|             Adriana Anggita Daeli (201524033)              |",
	"|            Pamudya Putra Pamungkas (201524058)             |",
	"|                                                            |",
	"|          JURUSAN TEKNIK KOMPUTER DAN INFORMATIKA           |",
 	"|                PRODI D-IV TEKNIK INFORMATIKA               |",
	"|                  POLITEKNIK NEGERI BANDUNG                 |",
	"|                           2021                             |",
 	"<============================================================>",
	"|                                                            |",
	"@============================================================~"
};

void replace(char t) 
{
	/* Modul yang mengkonversi char ke char tertentu berdasarkan ASCII */
	if(t == '=')
		printf ("%c", 205);
	else if(t == '|')
		printf ("%c", 186);
	else if(t == '#')
		printf ("%c", 206);
	else if(t == '&')
		printf ("%c", 203);
	else if(t == '<')
		printf ("%c", 204);
	else if(t == '>')
		printf ("%c", 185);
	else if(t == '%')
		printf ("%c", 202);
	else if(t == '{')
		printf ("%c", 201);
	else if(t == '}')
		printf ("%c", 187);
	else if(t == '@')
		printf ("%c", 200);
	else if(t == '~')
		printf ("%c", 188);
	else
		printf ("%c", t);
}

void mapMenu() 
{
	/* Menampilkan tampilan utama CALCO
	/* F.S. : String menu ditampilkan sebagai menu */
	
	/* Kamus Data */
	
	/* Algoritma */
	width = getWidth();
	height = getHeight();
	
	for (i = 0; i < 20; i++) {
		x = width / 2 - 31;
		y = height / 2 - 9;	
		gotoxy(x, y + i );	
		for (j = 0; j < 62; j++) {
			replace(menu[i][j]);
		}
	}
}

void mapCalStd() 
{
	/* Menampilkan tampilan utama fitur kalkulator standard */
	/* I.S. : - */
	/* F.S. : String menu ditampilkan sebagai menu */
	
	/* Kamus Data */
	
	/* Algoritma */
	width = getWidth();
	height = getHeight();
	
	for (i = 0; i < 18; i++) {
		x = width / 2 - 45;
		y = height / 2 - 9;	
		gotoxy(x, y + i );	
		for (j = 0; j < 93; j++) {
			replace(calStd[i][j]);
		}
	}
}

void mapCalProgIn()
{
	/* Menampilkan tampilan utama fitur kalkulator program */
	/* I.S. : Program belum berjalan */
	/* F.S. : Tampilan utama fitur kalkulator program sudah tampil */
	
	/* Kamus Data */
	
	/* Algoritma */
	width = getWidth();
	height = getHeight();
	
	for(i = 0; i < 15; i++){
		gotoxy(width/2-31, height/2 - 8 + i);
		for(j = 0; j < 62; j++){
			replace(calProgIn[i][j]);
		}
	}
}

void mapCalProgOut(int choice)
{
	/* Menampilkan tampilan fitur konversi sesuai dengan inputan user */
	/* I.S. : Program belum berjalan */
	/* F.S. : Tampilan fitur konversi sudah tampil */
	
	/* Kamus Data */
	
	/* Algoritma */
	width = getWidth();
	height = getHeight();
	
	for(i = 0; i < 16 ; i++){
		gotoxy(width/2-31, height/2 - 8 + i);
		for(j = 0; j < 62; j++){
			switch(choice){
				case 1:		// Convert from Decimal
					replace(calProgOut1[i][j]); break;
				case 2:		// Convert from Binary
					replace(calProgOut2[i][j]); break;
				case 3:		// Convert from Octadecimal
					replace(calProgOut3[i][j]); break;
				case 4:		// Convert from Hexadecimal
					replace(calProgOut4[i][j]); break;
			}
		}
	}
}

void mapGuide()
{
	/* Menampilkan tampilan fitur guide kepada user */
	/* I.S. : Program belum berjalan */
	/* F.S. : Tampilan fitur guide sudah tampil */
	
	/* Kamus Data */
	
	/* Algoritma */
	width = getWidth();
	height = getHeight();
	
	for (i = 0; i < 25; i++) {
		x = width / 2 - 45;
		y = height / 2 - 13;	
		gotoxy(x, y + i );	
		for (j = 0; j < 93; j++) {
			replace(guide[i][j]);
		}
	}
}

void mapCalStdGuide() 
{
	/* Menampilkan tampilan fitur guide calstd kepada user */
	/* I.S. : Program belum berjalan */
	/* F.S. : Tampilan fitur guide calstd sudah tampil */
	
	/* Kamus Data */
	
	/* Algoritma */
	width = getWidth();
	height = getHeight();
	
	for (i = 0; i < 24; i++) {
		x = width / 2 - 45;
		y = height / 2 - 11;	
		gotoxy(x, y + i );	
		for (j = 0; j < 94; j++) {
			replace(calStdGuide[i][j]);
		}
	}
}

void mapCalProgGuide() 
{
	/* Menampilkan tampilan fitur guide calprog kepada user */
	/* I.S. : Program belum berjalan */
	/* F.S. : Tampilan fitur guide calprog sudah tampil */
	
	/* Kamus Data */
	
	/* Algoritma */
	width = getWidth();
	height = getHeight();
	
	for (i = 0; i < 41; i++) {
		x = width / 2 - 44;
		y = height / 2 - 20;
		gotoxy(x, y + i );	
		for (j = 0; j < 89; j++) {
			replace(calProgGuide[i][j]);
		}
	}
}

void mapCredit() 
{
	/* Menampilkan tampilan fitur credit kepada user */
	/* I.S. : Program belum berjalan */
	/* F.S. : Tampilan fitur credit sudah tampil */
	
	/* Kamus Data */
	
	/* Algoritma */
	width = getWidth();
	height = getHeight();
	
	for (i = 0; i < 16; i++) {
		x = width / 2 - 31;
		y = height / 2 - 8;
		gotoxy(x, y + i );	
		for (j = 0; j < 63; j++) {
			replace(credit[i][j]);
		}
	}
}
