/* 
 * Program 			: map.h
 * Deskripsi 		: Deklarasi list  berkait dgn tampilan
 * Nama 			: Adriana Anggita D, Pamudya Putra P 
 * Tanggal			: 26 Juli 2021
 * Compiler			: Dev-C++
 * ==============================================================
 */

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>

#ifndef map_H
#define map_H

void screeMode();
	/* Membuat cmd mode fullscreen */
	
int getWidth();
	/* Mengembalikan value lebar tiap screen komputer */
	/* I.S. : - */
	/* F.S. : Lebar screen komputer diketahui */
	
int getHeight(); 
	/* Mengembalikan value tinggi tiap screen komputer */
	/* I.S. : - */
	/* F.S. : Tinggi screen komputer diketahui */
	
void gotoxy(int x, int y);
	/* Kursor untuk menunjuk pada titik (x,y) tertentu */
	
void mapMenu(int *choice);
	/* Menampilkan tampilan utama fitur kalkulator program */
	/* I.S. : - */
	/* F.S. : String menu ditampilkan sebagai menu */	
	
void mapCalProgIn();
	/* Menampilkan tampilan utama fitur kalkulator program */
	/* I.S. : Program belum berjalan */
	/* F.S. : Tampilan utama fitur kalkulator program sudah tampil */
	
void mapCalProgOut(int choice);
	/* Menampilkan tampilan fitur konversi sesuai dengan inputan user */
	/* I.S. : Program belum berjalan */
	/* F.S. : Tampilan fitur konversi sudah tampil */
	
void replace(char t);
	/* Modul yang mengkonversi char ke char tertentu berdasarkan ASCII */
#endif
