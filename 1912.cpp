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

int N;
int arr[100001];
int cash[100001];

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	cash[0] = arr[0];
	for (int i = 1; i < N; i++) {
		if (cash[i - 1] + arr[i] > arr[i]) cash[i] = cash[i - 1] + arr[i];
		else cash[i] = arr[i];
	}
	int max = cash[0];
	for (int i = 1; i < N; i++)	if (max < cash[i]) max = cash[i];
	cout << max << endl;
	return 0;
}