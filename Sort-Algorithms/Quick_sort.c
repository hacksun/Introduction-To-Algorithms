#include <stdio.h>

void swap(int *c, int *b)
{
	int temp;
	temp = *c;
	*c = *b;
	*b = temp;
}

int partition(int a[], int p, int r) {
	int i, j;
	i = p - 1;
	for (j = p;j <r;j++) {
		if (a[j] <= a[r]) {
			i = i + 1;
			swap(&a[i], &a[j]);
		}
	}
	swap(&a[i + 1], &a[r]);
	return i + 1;
}

void Quick_sort(int a[],int p, int r) {
	int q;
	if (p < r) {
		q = partition(a, p, r);
		Quick_sort(a, p, q - 1);
		Quick_sort(a, q+1, r);
	}

}



int main() {
	int a[10] = {1,2,3,4,5,6,7,8,9,10};

	Quick_sort(a, 0, 9);
	for (int i = 0;i <= 9;i++) {
		printf("%d ", a[i]);
	}
	getchar();
	return 0;
}