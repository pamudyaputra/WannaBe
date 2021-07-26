/* Program : calprog.c
 * Deskripsi : Implementasi fitur kalkulator program
 * Author : Pamudya Putra Pamungkas - 201524058
 * Tanggal : 26 Juli 2021
 */

#include "calprog.h"

/* Kamus Data */
int i, j, width, height;

/* Body Function/Procedure */

//void gotoxy(int x, int y) {
//	/* Kursor untuk menunjuk pada titik (x,y) tertentu */
//		
//  	COORD coord;
//  	coord.X = x;
//  	coord.Y = y;
//  	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
//}

char calProgIn[16][62] = {	// Tampilan Menu Utama Kalkulator Program
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
	"|                                                            |",
	"|       5. Back to Menu                                      |",
	"|                                                            |",
	"|  Your Choice : [ ][ENTER]                                  |",
	"|                                                            |",
	"(============================================================)"
};

void showCalProgIn(){
	/* Menampilkan tampilan utama fitur kalkulator program */
	/* I.S. : Program belum berjalan */
	/* F.S. : Tampilan utama fitur kalkulator program sudah tampil */
	
	/* Kamus Data */
	
	/* Algoritma */
	width = getWidth();
	height = getHeight();
	
	for(i = 0; i < 16; i++){
		gotoxy(width/2-31, height/2 - 8 + i);
		for(j = 0; j < 62; j++){
			replace(calProgIn[i][j]);
		}
	}
}

char calProgOut1[16][62] = {	// Tampilan fitur ketika user input 1
	"{============================================================}",
	"| Type Decimal Number ['0' to go back to menu]               |",
	"|[                                                          ]|",
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

char calProgOut2[16][62] = {	// Tampilan fitur ketika user input 2
	"{============================================================}",
	"| Type Binary Number ['0' to go back to menu]                |",
	"|[                                                          ]|",
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

char calProgOut3[16][62] = {	// Tampilan fitur ketika user input 3
	"{============================================================}",
	"| Type Octadecimal Number ['0' to go back to menu]           |",
	"|[                                                          ]|",
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

char calProgOut4[16][62] = {	// Tampilan fitur ketika user input 4
	"{============================================================}",
	"| Type Hexadecimal Number ['0' to go back to menu]           |",
	"|[                                                          ]|",
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

void showCalProgOut(int choice){
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

//void replace(char t){
//	if(t == '=')
//		printf ("%c", 205);
//	else if(t == '|')
//		printf ("%c", 186);
//	else if(t == '#')
//		printf ("%c", 206);
//	else if(t == '^')
//		printf ("%c", 203);
//	else if(t == '<')
//		printf ("%c", 204);
//	else if(t == '>')
//		printf ("%c", 185);
//	else if(t == '%')
//		printf ("%c", 202);
//	else if(t == '{')
//		printf ("%c", 201);
//	else if(t == '}')
//		printf ("%c", 187);
//	else if(t == '(')
//		printf ("%c", 200);
//	else if(t == ')')
//		printf ("%c", 188);
//	else
//		printf ("%c", t);
//}

void From(int opt){
	/* Pemilihan modul konversi berdasarkan pilihan */
	/* jenis bilangan yang akan dikonversi */
	/* I.S. : Jenis bilangan yang akan dikonversi sudah dipilih */
	/*		  tapi belum masuk ke proses konversi */
	/* F.S. : Modul proses konversi dijalankan */
	
	/* Kamus Data */
	
	/* Algoritma */
	switch(opt){
		case 1:
			FromDec();	// Convert Decimal
			break;
		case 2:
			FromBin();	// Convert Binary
			break;
		case 3:
			FromOct();	// Convert Octadecimal
			break;
		case 4:
			FromHex();	// Convert Hexadecimal
			break;
	}
}

void FromDec(){
	/* Mengkonversi bilangan Desimal ke jenis bilangan */
	/* yang dipilih */
	/* I.S. : Jenis bilangan yang akan dikonversi sudah dipilih */
	/*		  tapi belum dipilih jenis bilangan hasil konversinya */
	/* F.S. : Jenis bilangan hasil konversi sudah dipilih dan memulai */
	/*		  proses konversinya */
	
	/* Kamus Data */
	int dec;	// Decimal value
	
	/* Algoritma */
	// Print Layout
	showCalProgOut(1);
	
	// Scan User Input
	gotoxy(width/2-31+3, height/2-8+2); scanf("%d", &dec);
	
	if(dec == 0)
		return;		// Go back to menu
	
	// Print Decimal Value
	gotoxy(width/2-31+20, height/2-8+5);  printf("%d", dec);
	// Convert Decimal to Binary and Print Decimal Value
	gotoxy(width/2-31+20, height/2-8+7);  DecBin(dec);
	// Convert Decimal to Octadecimal and Print Octadecimal Value
	gotoxy(width/2-31+20, height/2-8+9);  DecOct(dec);
	// Convert Decimal to Hexadecimal and Print Hexadecimal Value
	gotoxy(width/2-31+20, height/2-8+11); DecHex(dec);

}

void FromBin(){
	/* Mengkonversi bilangan Biner ke jenis bilangan */
	/* yang dipilih */
	/* I.S. : Jenis bilangan yang akan dikonversi sudah dipilih */
	/*		  tapi belum dipilih jenis bilangan hasil konversinya */
	/* F.S. : Jenis bilangan hasil konversi sudah dipilih dan memulai */
	/*		  proses konversinya */
	
	/* Kamus Data */
	int dec;	// Decimal value
	
	/* Algoritma */
	dec = BinDec();	// Input & print binary value, converting Binary -> Decimal
	
	if(dec == 0)
		return;		// Go back to menu
	
	// Print Decimal Value
	gotoxy(width/2-31+20, height/2-8+5);   printf("%d", dec);
	// Convert Decimal to Octadecimal and Print Octadecimal Value
	gotoxy(width/2-31+20, height/2-8+9);   DecOct(dec);
	// Convert Decimal to Hexadecimal and Print Hexadecimal Value
	gotoxy(width/2-31+20, height/2-8+11);  DecHex(dec);
}

void FromOct(){
	/* Mengkonversi bilangan Octadesimal ke jenis bilangan */
	/* yang dipilih */
	/* I.S. : Jenis bilangan yang akan dikonversi sudah dipilih */
	/*		  tapi belum dipilih jenis bilangan hasil konversinya */
	/* F.S. : Jenis bilangan hasil konversi sudah dipilih dan memulai */
	/*		  proses konversinya */
	
	/* Kamus Data */
	int dec;	// Decimal value
	
	/* Algoritma */
	dec = OctDec();	// Input & print octadecimal value, converting Octa -> Decimal
	
	if(dec == 0)
		return;		// Go back to menu
	
	// Print Decimal Value
	gotoxy(width/2-31+20, height/2-8+5);  printf("%d", dec);
	// Convert Decimal to Binary and Print Binary Value
	gotoxy(width/2-31+20, height/2-8+7); DecBin(dec);
	// Convert Decimal to Hexadecimal and Print Octadecimal Value
	gotoxy(width/2-31+20, height/2-8+11); DecHex(dec);
}

void FromHex(){
	/* Mengkonversi bilangan Hexadesimal ke jenis bilangan */
	/* yang dipilih */
	/* I.S. : Jenis bilangan yang akan dikonversi sudah dipilih */
	/*		  tapi belum dipilih jenis bilangan hasil konversinya */
	/* F.S. : Jenis bilangan hasil konversi sudah dipilih dan memulai */
	/*		  proses konversinya */
	
	/* Kamus Data */
	int dec;	// Decimal value
	
	/* Algoritma */
	dec = HexDec();	// Input & print hexadecimal value, converting Hexa -> Decimal
	
	if(dec == 0)
		return;		// Go back to menu
	
	// Print Decimal Value
	gotoxy(width/2-31+20, height/2-8+5); printf("%d", dec);
	// Convert Decimal to Binary and Print Binary Value
	gotoxy(width/2-31+20, height/2-8+7); DecBin(dec);
	// Convert Decimal to Octadecimal and Print Octadecimal value
	gotoxy(width/2-31+20, height/2-8+9); DecOct(dec);
}

void DecBin(int dec){
	/* Mengkonversi bilangan Desimal ke Biner */
	/* I.S. : Bilangan desimal belum dikonversi ke biner */
	/* F.S. : Hasil konversi sudah ditampilkan */
	
	/* Kamus Data */
	int i=0, j=0;	// Iterator
	int bin[100];	// Binary Value
	
	/* Algoritma */
	while(dec != 0){
		bin[i] = dec%2;
		dec = (int)dec/2;
		i++;
	}
	
	// Print Result
	for(j = i-1; j>=0 ; j--){
		printf("%d", bin[j]);
	}
}

void DecOct(int dec){
	/* Mengkonversi bilangan Desimal ke Oktadesimal */
	/* I.S. : Bilangan desimal belum dikonversi ke oktadesimal */
	/* F.S. : Hasil konversi sudah ditampilkan */
	
	/* Kamus Data */
	int i=0, j=0;	// Iterator
	int oct[30];	// Octadecimal value
	
	/* Algoritma */
	while(dec != 0){
		oct[i] = dec%8;
		dec = (int)dec/8;
		i++; 
	}
	
	// Print Result
	for(j = i-1 ; j>=0 ; j--){
		printf("%d", oct[j]);
	}
}

void DecHex(int dec){
	/* Mengkonversi bilangan desimal ke hexadesimal */
	/* I.S. : Bilangan desimal belum dikonversi ke heksadesimal */
	/* F.S. : Hasil konversi sudah ditampilkan */
	
	/* Kamus Data */
	int i=0, j=0;	// Iterator
	int mod;		// Modulus value
	char hex[20];	// Hexadecimal value
	
	/* Algoritma */
	while(dec!=0){
		if(dec%16 > 9){
			switch(dec%16){
				case 10:
					hex[i] = 'A';
					i++;
					break;
				case 11:
					hex[i] = 'B';
					i++;
					break;
				case 12:
					hex[i] = 'C';
					i++;
					break;
				case 13:
					hex[i] = 'D';
					i++;
					break;
				case 14:
					hex[i] = 'E';
					i++;
					break;
				case 15:
					hex[i] = 'F';
					i++;
					break;
			}
			dec = dec/16;
		} else {
			mod = dec%16 + '0';
			hex[i] = mod;
			dec = dec/16;
			i++;
		}
	}
	
	// Print Result
	for(j = i-1 ; j>=0 ; j--){
		printf("%c", hex[j]);
	}
}

int BinDec(){
	/* Mengkonversi bilangan Biner ke Desimal */
	/* dan mengembalikan hasil konversinya */
	/* I.S. : Bilangan biner belum dikonversi ke desimal */
	/* F.S. : Bilangan inputan biner sudah di print dan */
	/* 		  bilangan desimal hasil konversi sudah dikembalikkan */
	
	/* Kamus Data */
	char bin[100];	// Binary value by user input
	int dec = 0;	// Decimal value
	int i;			// Iterator
	int check = 1;	// Validity checker
	
	/* Algoritma */ 
	while(1){
		// Print Layout
		showCalProgOut(2);
		
		// Scan User Input
		gotoxy(width/2-31+3, height/2-8+2); getchar(); scanf("%[^\n]s", &bin);
		
		check = 1;
	
		if(strcmp(bin,"0") == 0)
			return 0;	// Go back to menu
			
		for(i = 0; i < strlen(bin)-1 ; i++){
			if(bin[i] == '1' || bin[i] == '0'){
				
			} else {	// if binary value contains other than 0 or 1 number
				gotoxy(width/2-31+3, height/2-8+2); printf("The input isn't following the rules! Please input again!");
				gotoxy(width/2-31+2, height/2-8+14); printf("Press any key to go continue... ");
				getch();
				check = 0;
				break;	// endfor
			}
		}
		if(check == 1)
			break;	// endwhile
	}
	
	// Print Binary Value
	gotoxy(width/2-31+20, height/2-8+7); printf("%s", bin);
	
	// Binary to Decimal Converter
	for(i = 0 ; i < strlen(bin)-1 ; i++){
		if(bin[i] == '1'){
			dec = dec*2 + 1;
		} else {
			dec = dec*2;
		} 
	}
	return dec;
}

int OctDec(){
	/* Mengkonversi bilangan Oktadesimal ke Desimal */
	/* dan mengembalikan hasil konversinya */
	/* I.S. : Bilangan oktadesimal belum dikonversi ke desimal */
	/* F.S. : Bilangan inputan oktal sudah di print dan */
	/*		  bilangan desimal hasil konversi sudah dikembalikkan */
	/* Sumber referensi algoritma : https://www.programiz.com/c-programming/examples/octal-decimal-convert */
	/* Dimodifikasi oleh : Pamudya Putra Pamungkas */
	
	/* Kamus Data */
	int dec = 0;	// Decimal value
	int oct; 		// Octadecimal value by user input
	int i=0;		// Iterator
	int check;		// Validity checker
	
	/* Algoritma */
	while(1){
		// Print Layout
		showCalProgOut(3);
		// Scan User Input
		gotoxy(width/2-31+3, height/2-8+2); scanf("%d", &oct);
		
		check = oct;
	
		if(oct == 0)
			return 0;	// Go back to menu
		
		while(check != 0){
				if(check%10 > 7){	// if octal number contains >7 number
					gotoxy(width/2-31+3, height/2-8+2); printf("The input isn't following the rules! Please input again!");
					gotoxy(width/2-31+2, height/2-8+14); printf("Press any key to go continue... ");
					getch();
					break;	// endwhile
				}
			check /= 10;
		}
		if(check == 0)
			break;	// endwhile
	}
	
	// Print Octadecimal Value
	gotoxy(width/2-31+20, height/2-8+9); printf("%d", oct);
	
	// Octadecimal to Decimal Converter
	while(oct != 0){
		dec += (oct%10) * pow(8,i);
		i++;
		oct /= 10;
	}
	return dec;
}

int HexDec(){
	/* Mengkonversi bilangan Hexadesimal ke Desimal */
	/* dan mengembalikan hasil konversinya */
	/* I.S. : Bilangan heksadesimal belum dikonversi ke desimal */
	/* F.S. : Bilangan inputan heksadesimal sudah di print dan */
	/*		  bilangan desimal hasil konversi sudah dikembalikkan */
	/* Sumber referensi algoritma : https://aticleworld.com/c-program-to-convert-hexadecimal-to-decimal/ */
	/* Dimodifikasi oleh : Pamudya Putra Pamungkas */
	
	/* Kamus Data */
	char hex[20];	// Hexadecimal value by user input
	int dec=0; 		// Decimal value
	int base=1;		// Base Number
	int i=0;		// Iterator
	int len;		// User Input Length
	int check = 1;	// Validity Checker
	
	/* Algoritma */
	while(1){
		// Print Layout
		showCalProgOut(4);
		// Scan User Input
		gotoxy(width/2-31+3, height/2-8+2); getchar(); scanf("%[^\n]s", &hex);
		
		check = 1;
		len = strlen(hex);
		
		// Uppercasing all chars
		for(i = 0; i < len ; i++){
			hex[i] = toupper(hex[i]);
		}
		
		if(strcmp(hex, "0") == 0)
			return 0; 	// Go back to menu
		
		// Validity Check
		for(i = 0; i < len; i++){
			if(hex[i] >= '0' && hex[i] <= '9'){
				check = 1;
			} else if (hex[i] >= 'A' && hex[i] <= 'F'){
				check = 1;
			} else {
				gotoxy(width/2-31+3, height/2-8+2); printf("The input isn't following the rules! Please input again!");
				gotoxy(width/2-31+2, height/2-8+14); printf("Press any key to go continue... ");
				getch();
				check = 0;
				break;	// endfor
			}
		}
		if(check == 1){
			break;		// endwhile
		}
	}
	
	// Print Hexadecimal Value
	gotoxy(width/2-31+20, height/2-8+11); printf("%s", hex);
	
	// Hexadecimal to Decimal Converter
	for(i = len--; i>=0 ; i--){
		if(hex[i] >= '0' && hex[i] <= '9'){
			dec += (hex[i] - 48) * base;
			base *= 16;
		}
		else if(hex[i] >= 'A' && hex[i] <= 'F'){
			dec += (hex[i] - 55) * base;
			base *= 16;
		}
	}
	return dec;
}

//void screenMode(){
//	// Screen color	
//	system("color f0");
//		
//    // Screen mode full
//    ShowWindow(GetConsoleWindow(), SW_SHOWMAXIMIZED);
//}

//int getWidth() {	
//	CONSOLE_SCREEN_BUFFER_INFOEX info = {0};
//    HANDLE hConsole = NULL;
//    
//    // Get width of this window
//    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//    info.cbSize = sizeof(info);
//    GetConsoleScreenBufferInfoEx(hConsole, &info);
//
//    width = info.srWindow.Right;
//	
//	return width;
//}

//int getHeight() {	
//	CONSOLE_SCREEN_BUFFER_INFOEX info = {0};
//    HANDLE hConsole = NULL;
//
//    // Get height of this window
//    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//    info.cbSize = sizeof(info);
//    GetConsoleScreenBufferInfoEx(hConsole, &info);
//
//    height = info.srWindow.Bottom;
//    
//	return height;
//}

//int main(){
//	CalProg();
//	
//	return 0;
//}

void CalProg(){
	/* Kalkulator Program untuk mengkonversi sistem bilangan */
	/* Desimal, Biner, Octadesimal, atau Hexadesimal ke sistem lainnya */
	/* I.S. : Program belum berjalan */
	/* F.S. : Layar akan menampilkan bilangan yang diinput dan */
	/*		  semua hasil konversi ke sistem bilangan yang lainnya */
	
	/* Kamus Data */
	int choice;
	
	/* Algoritma */
	width = getWidth();
	height = getHeight();
	
	screenMode();
	while(1){
		showCalProgIn();
		gotoxy(width/2-31+18, height/2-8+13); scanf("%d", &choice);
		if(choice > 0 && choice < 5){
			system("cls");
			From(choice);
			gotoxy(width/2-31+2, height/2-8+14); printf("Press any key to go back... "); getch();
			system("cls");
		}
		if(choice == 5)
			return;	
	}
}
