#define  _CRT_SECURE_NO_WARNINGS 
#include"game.h"

int jiance(char mine[ROWS][COLS],char show[ROWS][COLS])
{
	int i, j,n=0;
	for (i = 1; i <= ROW; i++)
	{
		for (j = 1; j <= COL; j++)
		{
			if (mine[i][j] == '0' && show[i][j] != '#')
				n++;
			if(n==COL*ROW-EASYCOUNT)
			 return 0;
			if (mine[i][j] == '1' && show[i][j] == '#')
				continue;
		}
	}
	return 1;
}
void play(char show[ROWS][COLS],char mine[ROWS][COLS], int x, int y)
{
	if (mathcount(mine, x, y)==0)
	{
		show[x][y] = ' ';
		if ((x - 1) > 0 && (y - 1) > 0 && (show[x - 1][y - 1] == '#'))
			play(show,mine, x - 1, y - 1);
		if ((x - 1) > 0 && (y) > 0 && (show[x - 1][y] == '#'))
			play(show, mine,x - 1, y);
		if ((x - 1) > 0 && (y + 1) > 0 && (show[x - 1][y + 1] == '#'))
			play(show, mine,x - 1, y + 1);
		if ((x) > 0 && (y - 1) > 0 && (show[x][y - 1] == '#'))
			play(show, mine,x, y - 1);
		if ((x) > 0 && (y + 1) > 0 && (show[x][y + 1] == '#'))
			play(show, mine,x, y + 1);
		if ((x + 1) > 0 && (y - 1) > 0 && (show[x + 1][y - 1] == '#'))
			play(show, mine,x + 1, y - 1);
		if ((x + 1) > 0 && (y) > 0 && (show[x + 1][y] == '#'))
			play(show, mine,x + 1, y);
		if ((x + 1) > 0 && (y + 1) > 0 && (show[x + 1][y + 1] == '#'))
			play(show, mine,x + 1, y + 1);
	}
	else {
		int n = mathcount(mine, x, y);
		show[x][y] = '0' + n;

	}
}
int mathcount(char board[ROWS][COLS], int x, int y)
{
	return (board[x - 1][y - 1]-'0')
		+ (board[x - 1][y]-'0')
		+ (board[x - 1][y + 1]-'0')
		+ (board[x][y - 1]-'0')
		+ (board[x][y + 1]-'0')
		+ (board[x + 1][y - 1]-'0')
		+ (board[x + 1][y]-'0')
		+ (board[x + 1][y + 1] - '0');
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
	for (i = 0; i <= row;i++)
	{
		printf("----");
	}
	printf("\n");
	for (i = 0; i <= row; i++)
	{
		printf("| %d ", i);
		if (i == row)
			printf("|");
	}
	printf("\n");
	for (i = 0; i <= row; i++)
	{
		printf("----");
	}
	printf("\n");
	for ( i = 1; i<=row; i++)
	{
		printf("| %d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("| %c ", board[i][j]);
			if ( j == col)
				printf("|");
		}
		printf("\n");
		for (j = 0; j <= row; j++)
		{
			printf("----");
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
	int x, y;
		while (jiance(mine,show)) {
			printf("\n输入欲排查坐标:");
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
					play(show,mine, x, y);
					huizhi(show, ROW, COL);
				}
			}
			else
				printf("坐标非法重新输入：");
		}
		if (jiance(mine,show)==0)
			printf("you win!\n");
}