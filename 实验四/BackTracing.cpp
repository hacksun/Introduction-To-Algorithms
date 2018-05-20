#include <stdio.h>
#include <conio.h>
#include<stdlib.h>

int n;//物品数量
int c;//背包容量
int v[100] ;
int w[100] ;
int cw = 0;
int cp = 0;
int bestp = 0;
int perp[100];
int order[100];
int put[100];

			 
void knapsack()
{
	int i, j;
	int temporder = 0;
	int temp = 0;

	for (i = 1;i <= n;i++)
		perp[i] = v[i] / w[i];
	for (i = 1;i <= n - 1;i++)
	{
		for (j = i + 1;j <= n;j++)
			if (perp[i]<perp[j])
			{
				temp = perp[i];
				perp[i] = perp[i];
				perp[j] = temp;

				temporder = order[i];
				order[i] = order[j];
				order[j] = temporder;
				temp = v[i];
				v[i] = v[j];
				v[j] = temp;

				temp = w[i];
				w[i] = w[j];
				w[j] = temp;
			}
	}
}

//回溯函数
void backtrack(int i)
{
	int bound(int i);
	if (i>n)
	{
		bestp = cp;
		return;
	}
	if (cw + w[i] <= c)
	{
		cw += w[i];
		cp += v[i];
		put[i] = 1;
		backtrack(i + 1);
		cw -= w[i];
		cp -= v[i];
	}
	if (bound(i + 1)>bestp)
		backtrack(i + 1);
}

//计算上界函数
int bound(int i)
{
	int leftw = c - cw;
	int b = cp;
	while (i <= n&&w[i] <= leftw)
	{
		leftw -= w[i];
		b += v[i];
		i++;
	}
	if (i <= n)
		b += v[i] / w[i] * leftw;
	return b;

}


int main()
{
	
	int i;
	printf("请输入物品的数量和容量：");
	scanf_s("%d %lf", &n, &c);
	printf("请输入物品的重量和价值：");
	for (i = 1;i <= n;i++)
	{
		printf("第%d个物品的重量：", i);
		scanf_s("%lf", &w[i]);
		printf("价值是：");
		scanf_s("%lf", &v[i]);
		order[i] = i;
	}
	
	knapsack();
	backtrack(1);
	printf("最有价值为：%lf\n", bestp);
	printf("需要装入的物品编号是：");
	for (i = 1;i <= n;i++)
	{
		if (put[i] == 1)
			printf("%d ", order[i]);
	}
	system("PAUSE");
	return 0;
}