#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#define MAX 65535;
int main()
{
	int e[10][10], k, i, j, n, m, t1, t2, t3;
	scanf_s("%d %d", &n, &m);
	for (i = 1;i <= n;i++)
		for (j = 1;j <= n;j++)
			if (i == j) e[i][j] = 0;
			else e[i][j] = MAX;

			for (i = 1;i <= m;i++)
			{
				scanf_s("%d %d %d", &t1, &t2, &t3);
				e[t1][t2] = t3;
			}

			for (k = 1;k <= n;k++)
				for (i = 1;i <= n;i++)
					for (j = 1;j <= n;j++)
						if (e[i][j]>e[i][k] + e[k][j])
							e[i][j] = e[i][k] + e[k][j];

			for (i = 1;i <= n;i++)
			{
				for (j = 1;j <= n;j++)
				{
					printf("%10d", e[i][j]);
				}
				printf("\n");
			}
			system("pause");
			return 0;
}
