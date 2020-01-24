#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>

using namespace std;

#define MAX 1001

int N;
int result = 0;
int arr[MAX];
int DP[2][MAX];

void func() {
	for (int i = 0; i < N; i++) {
		DP[0][i] = 1;
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j] && DP[0][j] + 1 > DP[0][i])
				DP[0][i] = DP[0][j] + 1;
		}
	}
	for (int i = N - 1; i >= 0; i--) {
		DP[1][i] = 1;
		for (int j = N - 1; j >= i; j--)
			if (arr[i] > arr[j] && DP[1][j] + 1 > DP[1][i])
				DP[1][i] = DP[1][j] + 1;
	}
}

void init() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}

int main() {
	init();
	cin >> N;
	
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	func();
	for (int i = 0; i < N; i++)
		result = max(result, (DP[0][i] + DP[1][i]));

	cout << result - 1;
	return 0;
}