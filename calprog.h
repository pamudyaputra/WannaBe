/* Program : calprog.h
 * Deskripsi : Header file implementasi fitur kalkulator program
 * Author : Pamudya Putra Pamungkas - 201524058
 * Tanggal : 26 Juli 2021
 */

#ifndef calprog_H
#define calprog_H

#include <stdio.h>
#include <windows.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include "map.h"

void From(int opt);
/* Pemilihan modul konversi berdasarkan pilihan */
/* jenis bilangan yang akan dikonversi */
/* I.S. : Jenis bilangan yang akan dikonversi sudah dipilih */
/*		  tapi belum masuk ke proses konversi */
/* F.S. : Modul proses konversi dijalankan */

void FromDec();
/* Mengkonversi bilangan Desimal ke jenis bilangan */
/* yang dipilih */
/* I.S. : Jenis bilangan yang akan dikonversi sudah dipilih */
/*		  tapi belum dipilih jenis bilangan hasil konversinya */
/* F.S. : Jenis bilangan hasil konversi sudah dipilih dan memulai */
/*		  proses konversinya */

void FromBin();
/* Mengkonversi bilangan Biner ke jenis bilangan */
/* yang dipilih */
/* I.S. : Jenis bilangan yang akan dikonversi sudah dipilih */
/*		  tapi belum dipilih jenis bilangan hasil konversinya */
/* F.S. : Jenis bilangan hasil konversi sudah dipilih dan memulai */
/*		  proses konversinya */

void FromOct();
/* Mengkonversi bilangan Octadesimal ke jenis bilangan */
/* yang dipilih */
/* I.S. : Jenis bilangan yang akan dikonversi sudah dipilih */
/*		  tapi belum dipilih jenis bilangan hasil konversinya */
/* F.S. : Jenis bilangan hasil konversi sudah dipilih dan memulai */
/*		  proses konversinya */

void FromHex();
/* Mengkonversi bilangan Hexadesimal ke jenis bilangan */
/* yang dipilih */
/* I.S. : Jenis bilangan yang akan dikonversi sudah dipilih */
/*		  tapi belum dipilih jenis bilangan hasil konversinya */
/* F.S. : Jenis bilangan hasil konversi sudah dipilih dan memulai */
/*		  proses konversinya */

void DecBin(int dec);
/* Mengkonversi bilangan Desimal ke Biner */
/* I.S. : Bilangan desimal belum dikonversi ke biner */
/* F.S. : Hasil konversi sudah ditampilkan */

void DecOct(int dec);
/* Mengkonversi bilangan Desimal ke Oktadesimal */
/* I.S. : Bilangan desimal belum dikonversi ke oktadesimal */
/* F.S. : Hasil konversi sudah ditampilkan */

void DecHex(int dec);
/* Mengkonversi bilangan desimal ke hexadesimal */
/* I.S. : Bilangan desimal belum dikonversi ke heksadesimal */
/* F.S. : Hasil konversi sudah ditampilkan */

int BinDec();
/* Mengkonversi bilangan Biner ke Desimal */
/* dan mengembalikan hasil konversinya */
/* I.S. : Bilangan biner belum dikonversi ke desimal */
/* F.S. : Bilangan inputan biner sudah di print dan */
/* 		  bilangan desimal hasil konversi sudah dikembalikkan */

int OctDec();
/* Mengkonversi bilangan Oktadesimal ke Desimal */
/* dan mengembalikan hasil konversinya */
/* I.S. : Bilangan oktadesimal belum dikonversi ke desimal */
/* F.S. : Bilangan inputan oktal sudah di print dan */
/*		  bilangan desimal hasil konversi sudah dikembalikkan */
/* Sumber referensi algoritma : https://www.programiz.com/c-programming/examples/octal-decimal-convert */
/* Dimodifikasi oleh : Pamudya Putra Pamungkas */
	
int HexDec();
/* Mengkonversi bilangan Hexadesimal ke Desimal */
/* dan mengembalikan hasil konversinya */
/* I.S. : Bilangan heksadesimal belum dikonversi ke desimal */
/* F.S. : Bilangan inputan heksadesimal sudah di print dan */
/*		  bilangan desimal hasil konversi sudah dikembalikkan */
/* Sumber referensi algoritma : https://aticleworld.com/c-program-to-convert-hexadecimal-to-decimal/ */
/* Dimodifikasi oleh : Pamudya Putra Pamungkas */

void CalProg();
/* Kalkulator Program untuk mengkonversi sistem bilangan */
/* Desimal, Biner, Octadesimal, atau Hexadesimal ke sistem lainnya */
/* I.S. : Program belum berjalan */
/* F.S. : Layar akan menampilkan bilangan yang diinput dan */
/*		  semua hasil konversi ke sistem bilangan yang lainnya */


#endif
