#include <stdio.h>

int DPMax_Sum(int a[],int n) {
	int maxsum = 0;
	int nowsum = 0;
	for (int i = 0;i < n;i++) {
		nowsum = nowsum + a[i];
		if (nowsum > maxsum) {
			maxsum = nowsum;
		}
		if (nowsum < 0)
			nowsum = 0;
	}
	printf("最大值为：%d", maxsum);
	return maxsum;
}

int main() {
	int a[100] = {-2,11,-4,13,-5,-2};
	DPMax_Sum(a, 6);
	getchar();
	return 0;

}