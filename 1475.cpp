#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<string.h>
#include<math.h>
#include<map>
#include<algorithm>

using namespace std;

int arr[9] = {0, }; // 숫자 배열
string num;

int main() {
	cin >> num;
	for (int i = 0; ;i++) {
		if (num[i] == '\0') break;
		int temp;
		temp = num[i] - '0';
		if (temp == 9) temp = 6;
		arr[temp]++;
	}
	if (arr[6] % 2 == 0) arr[6]/= 2;
	else arr[6] = arr[6]/2 + 1;
	sort(arr, arr + 9);
	cout << arr[8];
	return 0;
}