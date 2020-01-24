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

int N, M;
int arr[501][501];
int DP[501][501];
int dx[4] = { 1 , -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };


int DFS(int x, int y) {
	if (x == 0 && y == 0) return 1;

	if (DP[x][y] == -1) {
		DP[x][y] = 0;
		for (int i = 0; i < 4; i++) {
			int nX = x + dx[i];
			int nY = y + dy[i];

			if (x < 0 || x >= N || y < 0 || y >= M)	continue;
			if (arr[nX][nY] > arr[x][y])	DP[x][y] += DFS(nX, nY);
		}
	}
	return DP[x][y];
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)	{
			cin >> arr[i][j];
			DP[i][j] = -1;
		}
	}
	cout << DFS(N - 1, M - 1);
	return 0;
}