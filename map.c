/* 
 * Program 			: map.c
 * Deskripsi 		: Body list berkait dgn tampilan
 * Nama 			: Adriana Anggita D, Pamudya Putra P 
 * Tanggal			: 26 Juli 2021
 * Compiler			: Dev-C++
 * ==============================================================
 */


# include "map.h"

int i, j, width, height, x, y;

void screenMode() 

{
	/* Membuat cmd mode fullscreen */
	
	/* Kamus Data */
	
	/* Algoritma */
	system("color f0");	   // Screen color	
		
    ShowWindow(GetConsoleWindow(), SW_SHOWMAXIMIZED); 	// Screen mode full
}

int getWidth() 
{	
	/* Mengembalikan value lebar tiap screen komputer */
	/* I.S. : - */
	/* F.S. : Lebar screen komputer diketahui */
		
	/* Kamus Data */
	
	/* Algoritma */	
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
	
	/* Kamus Data */
	
	/* Algoritma */	
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

void mapMenu(int *choice) 
{
	/* Menampilkan tampilan utama fitur kalkulator program */
	/* I.S. : - */
	/* F.S. : String menu ditampilkan sebagai menu */
	
	/* Kamus Data */
	
	/* Algoritma */
	width = getWidth();
	height = getHeight();
	
	for (i = 0; i < 18; i++) {
		x = width / 2 - 31;
		y = height / 2 - 8;	
		gotoxy(x, y + i );	
		for (j = 0; j < 62; j++) {
			replace(menu[i][j]);
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

char menu[18][63] = {
	"{============================================================}",
	"|               {==== {====} |     {==== {====}              |",
	"|               |     |    | |     |     |    |              |",
	"|               |     <====> |     |     |    |              |",
	"|               (==== |    | (==== (==== (====)              |",
	"|                       / Adriana Pamudya 2021/              |",
	"<============================================================>",
	"|                             MENU                           |",
	"<============================================================>",
	"| 1 - Calculator Standard                                    |",
	"| 2 - Calculator Program                                     |",
	"| 3 - History                                                |",
	"| 4 - Help                                                   |",
	"| 5 - Credit                                                 |",
	"| 0 - Exit                                                   |",
	"<============================================================>",
	"| Your choice of menu : [ ][ENTER]                           |",
	"(============================================================)"
};

char calProgIn[15][62] = {	
	"{============================================================}",
	"|                   Programming Calculator                   |",
	"<============================================================>",
	"|                        Convert From                        |",
	"<============================================================>",
	"|                                                            |",
	"|       1. Decimal                                           |",
	"|       2. Binary                                            |",
	"|       3. Octadecimal                                       |",
	"|       4. Hexadecimal                                       |",
	"|       0. Back to Menu                                      |",
	"|                                                            |",
	"|  Your Choice : [ ][ENTER]                                  |",
	"|                                                            |",
	"(============================================================)"
};

char calProgOut1[16][62] = {
	"{============================================================}",
	"| Type Decimal Number ['0' to go back to menu]               |",
	"| [                                                         ]|",
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
	"(============================================================)",
};

char calProgOut2[16][62] = {
	"{============================================================}",
	"| Type Binary Number ['0' to go back to menu]                |",
	"| [                                                         ]|",
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
	"(============================================================)",
};

char calProgOut3[16][62] = {	
	"{============================================================}",
	"| Type Octadecimal Number ['0' to go back to menu]           |",
	"| [                                                         ]|",
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
	"(============================================================)",
};

char calProgOut4[16][62] = {
	"{============================================================}",
	"| Type Hexadecimal Number ['0' to go back to menu]           |",
	"| [                                                         ]|",
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
	"(============================================================)",
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
	else if(t == '^')
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
	else if(t == '(')
		printf ("%c", 200);
	else if(t == ')')
		printf ("%c", 188);
	else
		printf ("%c", t);
}

