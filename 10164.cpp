#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

#define MAX 16

int N, M, K;
int check_x, check_y;
int DP[MAX][MAX];

void check_point() {
	if (K % M == 0) {
		check_x = (K / M);
		check_y = M;
	}
	else {
		check_x = K / M + 1;
		check_y = (K % M);
	}
}

void Start_Map() {
	for (int i = 1; i <= check_x; i++) {
		for (int j = 1; j <= check_y; j++) {
			if (i == 1 && j == 1) continue;
			DP[i][j] = DP[i - 1][j] + DP[i][j - 1];
		}
	}
	for (int i = check_x; i <= N; i++) {
		for (int j = check_y; j <= M; j++) {
			if (i == check_x && j == check_y) continue;
			DP[i][j] = DP[i - 1][j] + DP[i][j - 1];
		}
	}
}

void init() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}

int main() {
	init();
	cin >> N >> M >> K;
	if (K == 0) K = 1;
	DP[1][1] = 1;

	check_point();
	Start_Map();
	
	cout << DP[N][M];

	return 0;
}