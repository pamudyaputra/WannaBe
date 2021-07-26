# include "map.h"

int i, j, width, height, x, y;

void screenMode() 
{
	// Screen color	
	system("color f0");
		
    // Screen mode full
    ShowWindow(GetConsoleWindow(), SW_SHOWMAXIMIZED);
}

int getWidth() 
{	
		
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
	CONSOLE_SCREEN_BUFFER_INFOEX info = {0};
    HANDLE hConsole = NULL;
	
    // Get height of this window
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    info.cbSize = sizeof(info);
    GetConsoleScreenBufferInfoEx(hConsole, &info);

    height = info.srWindow.Bottom;
    
	return height;
}

/* Kursor untuk menunjuk pada titik (x,y) tertentu */
void gotoxy(int x, int y) 
{		
  	COORD coord;
  	coord.X = x;
  	coord.Y = y;
  	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
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


void mapMenu(int *choice) 
{
	width = (int)getWidth();
	height = (int)getHeight();
	
	for (i = 0; i < 18; i++) {
		x = width / 2 - 31;
		y = height / 2 - 8;	
		gotoxy(x, y + i );	
		for (j = 0; j < 62; j++) {
			replace(menu[i][j]);
		}
	}
}

void replace(char t) 
{
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
	//Player 1
	else if(t == ';')
		printf ("%c", 176);
	//Player 2
	else if(t == '*')
		printf ("%c", 177);
	//Player 3
	else if(t == '@')
		printf ("%c", 178);
	//Player 4
	else if(t == '!')
		printf ("%c", 219);
	//Player 5
	else if(t == '~')
		printf ("%c", 240);
	else
		printf ("%c", t);
}

