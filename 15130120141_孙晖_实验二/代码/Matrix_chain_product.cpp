#include<stdio.h>
#include<stdlib.h>
#define n 6
#define max 20000
int matrixChainOrder(int p[], int s[][n]);
void printOptimalParens(int s[][n], int i, int j);
void main()
{
	int k, s[n][n];
	int p[6] = { 10,3,15,12,7,2 };
	k = matrixChainOrder(p, s);
	printf("%d个矩阵相乘所需的标量乘法的最小值为：%d\n", n - 1, k);
	printf("最终的最优全括号形式为：\n");
	printOptimalParens(s, 1, 5);
	getchar();
}
void printOptimalParens(int s[][n], int i, int j)
{
	if (i == j)
		printf("A%d", i);
	else
	{
		printf("(");
		printOptimalParens(s, i, s[i][j]);
		printOptimalParens(s, s[i][j] + 1, j);
		printf(")");
	}
}
int matrixChainOrder(int p[], int s[][n])
{
	int i, l, j, k, c = n - 1;
	int q, m[n][n];
	for (i = 0;i<n;i++)
		for (j = 0;j<n;j++)
			m[i][j] = 0;
	for (i = 1;i<n;i++)
		m[i][i] = 0;

	for (l = 2;l <= c;l++)
	{
		for (i = 1;i <= c - l + 1;i++)
		{
			j = i + l - 1;
			m[i][j] = max;
			for (k = i;k<j;k++)
			{
				q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
				if (q<m[i][j])
				{
					m[i][j] = q;
					s[i][j] = k;
				}
			}
		}
	}
	return(m[1][n - 1]);
}