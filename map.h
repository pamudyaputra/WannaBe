#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>

#ifndef map_H
#define map_H

void screeMode();
int getWidth();
int getHeight(); 
void gotoxy(int x, int y);
void mapMenu(int *choice);
void replace(char t);

#endif
