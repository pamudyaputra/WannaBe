#include "calprog.h"

#ifndef calcstd_C
#define calcstd_C

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
			FromDec();	// Konversi dari Desimal ke...
			break;
		case 2:
			FromBin();	// Konversi dari Biner ke...
			break;
		case 3:
			FromOct();	// Konversi dari Octadesimal ke...
			break;
		case 4:
			FromHex();	// Konversi dari Hexadesimal ke...
			break;
	}
	gotoxy(0,8);
}

void FromDec(){
	/* Mengkonversi bilangan Desimal ke jenis bilangan */
	/* yang dipilih */
	/* I.S. : Jenis bilangan yang akan dikonversi sudah dipilih */
	/*		  tapi belum dipilih jenis bilangan hasil konversinya */
	/* F.S. : Jenis bilangan hasil konversi sudah dipilih dan memulai */
	/*		  proses konversinya */
	
	/* Kamus Data */
	int dec;
	
	/* Algoritma */
	gotoxy(1, 6); printf("Input : "); scanf("%d", &dec);
	
	gotoxy(32,2); printf("%d", dec);	// Print Decimal
	gotoxy(32,3); DecBin(dec);			// Convert to Binary and print
	gotoxy(32,4); DecOct(dec);			// Convert to Octal and print
	gotoxy(32,5); DecHex(dec);			// Convert to Hexa and print

}

void FromBin(){
	/* Mengkonversi bilangan Biner ke jenis bilangan */
	/* yang dipilih */
	/* I.S. : Jenis bilangan yang akan dikonversi sudah dipilih */
	/*		  tapi belum dipilih jenis bilangan hasil konversinya */
	/* F.S. : Jenis bilangan hasil konversi sudah dipilih dan memulai */
	/*		  proses konversinya */
	
	/* Kamus Data */
	int dec;
	
	/* Algoritma */
	dec = BinDec();
	gotoxy(32,2); printf("%d", dec);
	gotoxy(32,4); DecOct(dec);
	gotoxy(32,5); DecHex(dec);
}

void FromOct(){
	/* Mengkonversi bilangan Octadesimal ke jenis bilangan */
	/* yang dipilih */
	/* I.S. : Jenis bilangan yang akan dikonversi sudah dipilih */
	/*		  tapi belum dipilih jenis bilangan hasil konversinya */
	/* F.S. : Jenis bilangan hasil konversi sudah dipilih dan memulai */
	/*		  proses konversinya */
	
	/* Kamus Data */
	int dec;
	
	/* Algoritma */
	dec = OctDec();
	gotoxy(32,2); printf("%d", dec);
	gotoxy(32,3); DecBin(dec);
	gotoxy(32,5); DecHex(dec);
}

void FromHex(){
	/* Mengkonversi bilangan Hexadesimal ke jenis bilangan */
	/* yang dipilih */
	/* I.S. : Jenis bilangan yang akan dikonversi sudah dipilih */
	/*		  tapi belum dipilih jenis bilangan hasil konversinya */
	/* F.S. : Jenis bilangan hasil konversi sudah dipilih dan memulai */
	/*		  proses konversinya */
	
	/* Kamus Data */
	int dec;
	
	/* Algoritma */
	dec = HexDec();
	gotoxy(32,2); printf("%d", dec);
	gotoxy(32,3); DecBin(dec);
	gotoxy(32,4); DecOct(dec);
}

void DecBin(int dec){
	/* Mengkonversi bilangan Desimal ke Biner */
	/* I.S. : Bilangan desimal belum dikonversi ke biner */
	/* F.S. : Hasil konversi sudah ditampilkan */
	
	/* Kamus Data */
	int i = 0, j = 0;
	int bin[100];
	
	/* Algoritma */
	while(dec != 0){
		bin[i] = dec%2;
		dec = (int)dec/2;
		i++;
	}
	for(j = i-1; j>=0 ; j--){
		printf("%d", bin[j]);	// Print hasil
	}
}

void DecOct(int dec){
	/* Mengkonversi bilangan Desimal ke Oktadesimal */
	/* I.S. : Bilangan desimal belum dikonversi ke oktadesimal */
	/* F.S. : Hasil konversi sudah ditampilkan */
	
	/* Kamus Data */
	int i=0, j=0;
	int oct[30];
	
	/* Algoritma */
	while(dec != 0){
		oct[i] = dec%8;
		dec = (int)dec/8;
		i++; 
	}
	
//	gotoxy(0, 4); printf("Result : ");
	for(j = i-1 ; j>=0 ; j--){
		printf("%d", oct[j]);	// Print hasil
	}
}

void DecHex(int dec){
	/* Mengkonversi bilangan desimal ke hexadesimal */
	/* I.S. : Bilangan desimal belum dikonversi ke heksadesimal */
	/* F.S. : Hasil konversi sudah ditampilkan */
	
	/* Kamus Data */
	int i=0, j=0, mod;
	char hex[20];
	
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
	
	for(j = i-1 ; j>=0 ; j--){
		printf("%c", hex[j]);	// Print hasil
	}
}

int BinDec(){
	/* Mengkonversi bilangan Biner ke Desimal */
	/* dan mengembalikan hasil konversinya */
	/* I.S. : Bilangan biner belum dikonversi ke desimal */
	/* F.S. : Bilangan inputan biner sudah di print dan */
	/* 		  bilangan desimal hasil konversi sudah dikembalikkan */
	
	/* Kamus Data */
	char bin[100];
	int dec = 0;
	int i;
	
	/* Algoritma */
	gotoxy(1, 6); printf("Input : "); 
	fflush(stdin);
	fgets(bin, sizeof(bin), stdin);
	
	gotoxy(32,3); printf("%s", bin);
	
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
	int dec = 0, oct, i=0;
	
	/* Algoritma */
	gotoxy(1, 6); printf("Input : "); scanf("%d", &oct);
	
	gotoxy(32,4); printf("%d", oct);
	
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
	char hex[20];
	int dec=0, base=1;
	int i=0 , val, len;
	
	/* Algoritma */
	fflush(stdin);
	gotoxy(1, 6); printf("Input : "); fgets(hex,sizeof(hex),stdin);
	
	gotoxy(32,5); printf("%s", hex);
	
	len = strlen(hex);
	
	for(i = 0; i < len ; i++){
		hex[i] = toupper(hex[i]);
	}
	
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

void PrintTemplate(){
	/* Menampilkan template tampilan */
	/* I.S. : Template belum tertampil */
	/* F.S. : Template sudah tertampil */
	
	gotoxy(1,2); printf("1. Decimal");
	gotoxy(1,3); printf("2. Binary");
	gotoxy(1,4); printf("3. Octadecimal");
	gotoxy(1,5); printf("4. Hexadecimal");
	
	gotoxy(18,2); printf("Decimal     : ");
	gotoxy(18,3); printf("Binary      : ");
	gotoxy(18,4); printf("Octadecimal : ");
	gotoxy(18,5); printf("Hexadecimal : ");
	
	gotoxy(0,7); printf("Pilih :    ");
}

void CalProgram(){
	/* Kalkulator Program untuk mengkonversi sistem bilangan */
	/* Desimal, Biner, Octadesimal, atau Hexadesimal ke sistem lainnya */
	/* I.S. : Program belum berjalan */
	/* F.S. : Layar akan menampilkan bilangan yang diinput dan */
	/*		  semua hasil konversi ke sistem bilangan yang lainnya */
	
	/* Kamus Data */
	int choice = -1;
	
	/* Algoritma */
	system("cls");
	while(true){
		PrintTemplate();
		gotoxy(8,7); scanf("%d", &choice);
		if(choice == 1 || choice == 2 || choice == 3 || choice == 4){
			break;
		} else {
			gotoxy(0,8); printf("Input Nomor Salah! Coba Lagi!");
		}
	}
	From(choice);
}

#endif
