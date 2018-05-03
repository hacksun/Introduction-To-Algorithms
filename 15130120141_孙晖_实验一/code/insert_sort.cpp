#include "stdafx.h"
#include<iostream>
using namespace std;
void InsertSort(int a[], int n)
{
    for (int j = 1; j < n; j++)
    {
        int key = a[j]; 
        int i = j - 1;  
        while (i >= 0 && key < a[i])
        {
            a[i + 1] = a[i];
            i--;
        }
        a[i + 1] = key;
    }
}
void main() {
    int d[] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
    cout << "输入数组  { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 } " << endl;
    InsertSort(d,7);
    cout << "排序后结果：";
    for (int i = 0; i < 10; i++)
    {
        cout << d[i]<<" ";
    }
 
}