#include <stdio.h>
#include <string.h>
#include "stdlib.h"

void getCommon(char str1[], char str2[], char * str3);//吸取上一次实验的教训，先声明
int stringLength(char * str);

void main() {
	char str1[100] = { 'x','z','y','z','z','y','x' };
	char str2[100] = { 'z','x','y','y','z','x','z' };
	char str3[100];

	getCommon(str1, str2, str3);
	printf("%s\n", str3);
	getchar();
}
int stringLength(char * str) {
	int len = 0;
	while (*str != '\0') {
		len++;
		str++;
	}
	return len;
}
void getCommon(char str1[], char str2[], char * str3) {
	int len1, len2;
	int i, j, k;
	int max = 0;
	int start = -1;

	len1 = stringLength(str1);
	len2 = stringLength(str2);
	for (i = 0; i < len1; i++) {
		for (j = 0; j < len2; j++) {
			if (str1[i] == str2[j]) {
				for (k = 0; (str1[i + k] == str2[j + k] && str1[i + k] != '\0'); k++);
				if (max < k) {
					max = k;
					start = i;
				}
			}
		}
	}

	if (start == -1) {
		str3[0] = '\0';;
	}
	else {
		memcpy(str3, &str1[start], max);
		str3[max] = '\0';
	}
}