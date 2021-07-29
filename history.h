#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include "map.h"

#ifndef history_H
#define history_H

#define MAX_STR 100

typedef struct {
	char date[20];
	char time[10];
	char infix[MAX_STR];
	char tree[MAX_STR];
	char result[MAX_STR];
}stdHistory;

typedef struct {
	char date[20];
	char time[10];
	char dec[MAX_STR];
	char bin[MAX_STR];
	char oct[MAX_STR];
	char hex[MAX_STR];
	char from;
}progHistory;

void writeCalStd(char *infix, char* tree, double res);

void writeCalProg(progHistory prog);

void showStdHist();

void showProgHist();

void showHistMenu();

void History();






#endif
