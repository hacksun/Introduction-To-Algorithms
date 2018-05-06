#include<iostream>
#include <string.h> 
#include<stdlib.h>
#include <stdio.h>
#define N 6
#define MAX 99999 //本来打算用 INT_MAX来着
#define vertex 8
using namespace std;

struct Edge
{
	int u, v, w;
};

Edge edge[MAX];
int d[N];

int BellmanFord()
{
	bool flag = 1;
	for (int i = 2;i<N; i++)
		for (int j = 1; j <vertex + 1; j++)
		{
			if (d[edge[j].v] > d[edge[j].u] + edge[j].w)
			{
				d[edge[j].v] = d[edge[j].u] + edge[j].w;
			}
		}
	for (int j = 1; j <vertex + 1; j++)
	{
		if (d[edge[j].v] > d[edge[j].u] + edge[j].w)
		{
			flag = 0;
			break;
		}
	}
	return flag;
}

void init()
{
	memset(d, MAX, sizeof(d));
	d[1] = 0;
	for (int i = 1; i <= vertex; i++)
	{
		cin >> edge[i].u >> edge[i].v >> edge[i].w;
	}
}

void print()
{
	for (int i = 1; i < N; i++)
		printf("%d ", d[i]);
	printf("\n");
}

int main()
{
	init();
	printf("The path is:");
	if (BellmanFord())
		print();
	else
		printf("exist negative circle");
	system("pause");
	return 0;
}


