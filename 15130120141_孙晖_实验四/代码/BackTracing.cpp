#include <stdio.h>
#include <conio.h>
#include<stdlib.h>

int n;//��Ʒ����
int c;//��������
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

//���ݺ���
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

//�����Ͻ纯��
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
	printf("��������Ʒ��������������");
	scanf_s("%d %lf", &n, &c);
	printf("��������Ʒ�������ͼ�ֵ��");
	for (i = 1;i <= n;i++)
	{
		printf("��%d����Ʒ��������", i);
		scanf_s("%lf", &w[i]);
		printf("��ֵ�ǣ�");
		scanf_s("%lf", &v[i]);
		order[i] = i;
	}
	
	knapsack();
	backtrack(1);
	printf("���м�ֵΪ��%lf\n", bestp);
	printf("��Ҫװ�����Ʒ����ǣ�");
	for (i = 1;i <= n;i++)
	{
		if (put[i] == 1)
			printf("%d ", order[i]);
	}
	system("PAUSE");
	return 0;
}