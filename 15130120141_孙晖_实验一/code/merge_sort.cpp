#include <stdio.h>
#include <vector>
#include <limits.h>
using namespace std;


void merge(int *A,int p, int q, int r){
	int n1, n2;
	int x = 1;
	int y = 1;
	n1 = q - p + 1;
	n2 = r - q;
	vector<int> L;
	vector<int> R;
	for (int i = 1;i <= n1;i++) {
		L[i] = A[p + i - 1];
	}
	for (int j = 1;j<= n2;j++) {
		R[j] = A[q+j];
	}
	L[n1 + 1] = INT_MAX;
	R[n2 + 1] = INT_MAX;
	for (int k = p;k <= r;k++) {
		if (L[x] <= R[y]) {
			A[k] = L[x];
			x = x + 1;
		}
		else {
			A[k] = R[y];
			y = y + 1;
		}
	}

	
	
}

void merge_sort(int *A, int p, int r) {
	if (p < r) {
		int q = (p + r) / 2;
		merge_sort(A, p, q);
		merge_sort(A, q + 1, r);
		merge(A, p, q, r);
	}
}

int main() {
	int a[] = { 10,9,8,7,6,5,4,3,2,1 };
	merge_sort(a, 0, 9);
	for (int i = 0;i < 10;i++) {
		printf("%d ", a[i]);
	}
	getchar();
	return 0;
}