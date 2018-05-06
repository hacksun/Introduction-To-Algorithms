#include <stdio.h>
#include <string.h>
#define N 5 // the number of items
#define C 100// the capacity of bag

struct item{
	int value;
	int weight;
	float value_weight;
};

int main() {
	struct item items[N] = {
		{ 20,10,2.0 },
		{ 30,20,1.5 },
		{ 65,30,2.1 },
		{ 40,40,1.0 },
		{ 60,50,1.2 },
	};
	for (int i = 0;i<N - 1;i++)
		for (int j = 0;j<N-1-i;j++)
			if (items[j].value_weight<items[j+1].value_weight)
			{
				struct item temp;
				temp = items[j];
				items[j] = items[j+1];
				items[j+1] = temp;
			}
	for (int x = 0;x < N;x++)
		printf("%f ",items[x].value_weight);

	float value = 0;
	int capacity = 0;

	for (int y = 0;y < N;y++) {
		if (capacity <= C) {
			capacity = capacity + items[y].weight;
			value = value + items[y].value;
		}
		else {
			value = value + (100 - capacity)*items[y].value_weight;
			break;
		}
	}
	printf("\nThe highest value is: %.2f", value);
	getchar();
	return 0;
}