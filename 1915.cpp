#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>

using namespace std;

#define MAX 1001

int N, M;
int result = 0;
int arr[MAX][MAX];
int DP[MAX][MAX];

void Solve() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (i == 0 || j == 0)
				DP[i][j] = arr[i][j];

			else if (arr[i][j] == 1)
				DP[i][j] = min(DP[i - 1][j - 1], min(DP[i - 1][j], DP[i][j - 1])) + 1;
			
			result = max(result, DP[i][j]);
		}
	}
}

void init() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}

int main() {
	init();
	cin >> N >> M;
	
	for (int i = 0; i < N; i++) {
		string temp; cin >> temp;
		for (int j = 0; j < M; j++)
			arr[i][j] = temp[j] - '0';
	}

	Solve();
	cout << (result * result);
	return 0;
}