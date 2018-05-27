#include<iostream>  
#include<stdlib.h>
using namespace std;
int num;
int *x;
int sum;
bool place(int k)
{
	for (int j = 1;j<k;j++)
		if (abs(x[k] - x[j]) == abs(k - j) || x[j] == x[k])//判断条件
			return false;
	return true;

}
void backtrack(int t)
{
	if (t>num)  
	{
		sum++;
		
		for (int m = 1;m <= num;m++)
		{
			cout<< "<" << m << "," << x[m] << ">";
		}
		cout << endl;
	}
	else
		for (int i = 1;i <= num;i++)
		{
			x[t] = i;
			if (place(t))
				backtrack(t + 1);
		}
}
void main()
{
	num = 8;
	sum = 0;
	x = new int[num + 1];
	for (int i = 0;i <= num;i++)
		x[i] = 0;
	backtrack(1);
	cout << "共有" << sum <<"种方案"<< endl;
	delete[]x;
	system("PAUSE");

}