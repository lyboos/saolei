#define  _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include"game.h"
void menu()
{
	printf("**************************\n");
	printf("**********1£ºplay*********\n");
	printf("**********0£ºexit*********\n");
	printf("**************************\n");

}
void game()
{
	printf("É¨À×\n");
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };
	chushi(mine,ROWS,COLS,'0');
	chushi(show, ROWS, COLS,'#');
	huizhi(show,ROW,COL);
	setboom(mine, ROW, COL);
	player(mine, show, ROW, COL);
}
void start()
{
	int input;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("ÇëÑ¡Ôñ£º>");
		scanf("%d", &input);
		switch (input)
		{
		case 1: game();
			break;
		case 0:
			printf("ÒÑÍË³ö");
			break;
		}
	} while (input);
}
int main()
{
	start();
	return 0;
}