#define  _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include"game.h"
void menu()
{
	printf("**************************\n");
	printf("**********1��play*********\n");
	printf("**********0��exit*********\n");
	printf("**************************\n");

}
void game()
{
	printf("ɨ��\n");
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
		printf("��ѡ��>");
		scanf("%d", &input);
		switch (input)
		{
		case 1: game();
			break;
		case 0:
			printf("���˳�");
			break;
		}
	} while (input);
}
int main()
{
	start();
	return 0;
}