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

#define MAX 501

int n;
int arr[MAX][MAX];
int DP[MAX][MAX];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int DFS(int x, int y) {
    if (DP[x][y] > 0) return DP[x][y];
	DP[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
		if (arr[x][y] >= arr[nx][ny]) continue;
		
		DP[x][y] = max(DP[x][y], DFS(nx, ny) + 1);
	}
	return DP[x][y];
}

void init() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}

int main() {
	init();
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];

	int max_value = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			max_value = max(max_value, DFS(i, j));

	cout << max_value;
	return 0;
}