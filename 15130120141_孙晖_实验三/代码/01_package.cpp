#include<stdio.h>

int main()
{
	int arr[6][13] = { { 0 } };
	int value[6] = { 0 , 20 , 30 , 65 , 40 , 60 };
	int weight[6] = { 0 , 1 , 2 , 3 , 4 , 5 }; 
	int bagV = 10;

	for (int i = 1; i< 6; i++)
	{
		for (int j = 1; j <= 10; j++)
		{
			if (j < weight[i])
				arr[i][j] = arr[i - 1][j];
			else
				arr[i][j] =  arr[i - 1][j] > (arr[i - 1][j - weight[i]] + value[i]) ? arr[i - 1][j] : (arr[i - 1][j - weight[i]] + value[i]);
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	printf("%d ", arr[5][10]);
	getchar();
	return 0;
}