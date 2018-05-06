#include<stdio.h>

using namespace std;
int N = 4;
int A[5] = { 0, 15, 8, 3, 10 };

void MinHeapify(int i, int N)
{
	int l, r, small, swamp;
	l = 2 * i;
	r = 2 * i + 1;
	if (l <= N && A[l] < A[i])
		small = l;
	else small = i;
	if (r <= N && A[r] < A[small])
		small = r;
	if (small != i)
	{
		swamp = A[i];
		A[i] = A[small];
		A[small] = swamp;
		MinHeapify(small, N);
	}

}

void BuildMinHeap()
{
	for (int i = N / 2; i >= 1; i--)
	{
		MinHeapify(i, N);
	}
}

int HeapExtractMin(int &N)
{
	int min = A[1];
	A[1] = A[N];
	printf("%d ", min);
	--N;
	MinHeapify(1, N);
	return min;
}

int main(int argc, char *argv[])
{
	int k;
	double sum;
	int i = 0;
	double t[4];
	printf("调度顺序为：");
	BuildMinHeap();
	while (N)
	{
		t[i++] = HeapExtractMin(N);
	}
	k = i;
	sum = ((t[0] * k + t[1] * (k - 1) + t[2] * (k - 2) + t[3] * (k - 3)) / k);
	printf("\n最短平均完成时间为：%.2f", sum);
	printf("\n");
	getchar();
	return 0;
}
