#include<iostream>
#include<queue>
#include<vector>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<string.h>
#include<math.h>
#include<map>
#include<algorithm>

using namespace std;

int main() {
	char arr[500] = { 0, };
	char arr2[500];

	while (1) {
		scanf ("%[^\n]%*c", arr);

		int a = strlen(arr);
		int b = a - 1;

		if (arr[0] == 'E' && arr[1] == 'N' && arr[2] == 'D') break;

		for (int i = 0; i < a; i++) {

			arr2[i] = arr[b];
			printf("%c", arr2[i]);
			b--;
		}
		printf("\n");
	}
	return 0;
}