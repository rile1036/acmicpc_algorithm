#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>

using namespace std;

#define MAX 1001

int N;
int arr[MAX];
int DP[MAX];
int max_value = 0;

void Func() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i] && DP[i] < DP[j] + 1)
				DP[i] = DP[j] + 1;
		}
		max_value = max(max_value, DP[i]);
	}
}

void init() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}

int main() {
	init();
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		DP[i] = 1;
	}

	Func();

	cout << max_value;
	return 0;
}