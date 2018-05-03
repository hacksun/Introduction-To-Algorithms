#include<stdio.h>  
#include<string.h>  
int c[100][100];  
int b[100][100];   
char f[100];

int Max(int m, int n, int i, int j)
{
	if (m > n)
	{
		b[i][j] = -1;
		return m;
	}
	else
	{
		b[i][j] = 1;
		return n;
	}
}

void Print_LCS(int i, int j, int s, char x[], char y[])
{
	if (b[i][j] == 0)
	{
		f[s - 1] = x[i - 1];
		i--;j--;s--;
		Print_LCS(i, j, s, x, y);
	}
	else if (b[i][j] == -1)
	{
		i--;
		Print_LCS(i, j, s, x, y);
	}
	else if (b[i][j] == 1)
	{
		j--;
		Print_LCS(i, j, s, x, y);
	}
}

int LCS(char x[], char y[])
{
	int i, j;
	int x_len, y_len;
	x_len = strlen(x);
	y_len = strlen(y);
	printf("   ");
	for (i = 0;i < y_len;i++)
	{
		printf("%c  ", y[i]);
	}
	printf("\n");
	for (i = 1;i <= x_len;i++)
	{
		printf("%c  ", x[i - 1]);
		for (j = 1;j <= y_len;j++)
		{
			if (x[i - 1] == y[j - 1])
			{
				c[i][j] = c[i - 1][j - 1] + 1;
				b[i][j] = 0;
				printf("%d  ", c[i][j]);
			}
			else
			{
				c[i][j] = Max(c[i - 1][j], c[i][j - 1], i, j);
				printf("%d  ", c[i][j]);
			}
		}
		printf("\n");
	}

	printf("X和Y的LCS是:");
	Print_LCS(x_len, y_len, c[x_len][y_len], x, y);
	printf("%s", f);
	printf("\n");
	return c[x_len][y_len];
}


void main()
{
	char X[100] = {'x','z','y','z','z','y','x'};
	char Y[100] = {'z','x','y','y','z','x','z'};
	int i, j, s;
	printf("LCS的矩阵如下：\n");
	s = LCS(X, Y);
	printf("X和Y的LCS: %d \n", s);
	getchar();
}