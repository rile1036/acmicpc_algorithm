#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>

using namespace std;

#define MAX 201

int N;
int arr[MAX];
int DP[MAX];

void init() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}

int main() {
	init();
	cin >> N;

	for (int i = 1; i <= N; i++)
		cin >> arr[i];
	
	for (int i = 1; i <= N; i++) {
		DP[i] = 1;
		for (int j = 1; j < i; j++)
			if (arr[j] < arr[i] && DP[i] <= DP[j])
				DP[i] += 1;
	}
	
	int result = 0;
	for (int i = 1; i <= N; i++) result = max(result, DP[i]);

	cout << N - result;

	return 0;
}