#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define EASYCOUNT 10
void chushi(char board[ROWS][COLS], int rows, int cols,char set);
void huizhi(char board[ROWS][COLS], int row, int col);
void setboom(char board[ROWS][COLS], int row, int col); 
void player(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);
int mathcount(char board[ROWS][COLS], int x, int y);
//void jiance(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y,int win);
