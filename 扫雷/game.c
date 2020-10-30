#define  _CRT_SECURE_NO_WARNINGS 
#include"game.h"

int mathcount(char board[ROWS][COLS], int x, int y)
{
	return board[x - 1][y - 1]
		+ board[x - 1][y]
		+ board[x - 1][y + 1]
		+ board[x][y - 1]
		+ board[x][y + 1]
		+ board[x + 1][y - 1]
		+ board[x + 1][y]
		+ board[x + 1][y + 1] - 8 * '0';
}

void chushi(char board[ROWS][COLS], int rows, int cols,char set)
{
	int i=0, j;
	for (;i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}
void huizhi(char board[ROWS][COLS],int row,int col)
{
	int i, j;
	for (i = 0; i <= row; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for ( i = 1; i<=row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}

void setboom(char board[ROWS][COLS], int row, int col)
{
	int count = EASYCOUNT;
	while (count>0)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}

	}
}

void player(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x, y,win=0;
	printf("\n输入欲排查坐标:");
		while (win<row*col-EASYCOUNT) {
			scanf("%d %d", &x, &y);
			if (x >= 1 && x <= 9 && y >= 1 && y <= 9)
			{
				if (mine[x][y] == '1') {
					printf("you died!\nPS:1 FOR BOOM\n");
					huizhi(mine, ROW, COL);
					break;
				}
				else {
					int pointcount = mathcount(mine, x, y);
					show[x][y] = pointcount + '0';
					huizhi(show, ROW, COL);
					win++;
				}
			}
			else
				printf("坐标非法重新输入：");
		}
		if (win == row * col-EASYCOUNT)
			printf("you win!\n");
}