#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <math.h>
#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <string>
#include <string.h>
#include <map>

using namespace std;

#define MAX 501

int n, m;
int arr[MAX][MAX];
bool visit[MAX][MAX] = { false, };
int result = 0;
int result_check = 0;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

void init() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}

int DFS(int init_x, int init_y, int count, int sum) {
	if (count == 4) {
		result = max(result, sum);
		return result;
	}

	for (int i = 0; i < 4; i++) {
		int nx = init_x + dx[i];
		int ny = init_y + dy[i];
		if (nx >= 0 && ny >= 0 && nx < n && ny < m && visit[nx][ny] == false) {
			visit[nx][ny] = true;
			DFS(nx, ny, count + 1, sum + arr[nx][ny]);
			visit[nx][ny] = false;
		}
	}
}


void DFS_H() {
	for (int i = 1; i < n; i++) { // ㅗ
		for (int j = 1; j < m - 1; j++) {
			int ans = arr[i][j] + arr[i - 1][j] + arr[i][j - 1] + arr[i][j + 1];
			result = max(result, ans);
		}
	}
	for (int i = 0; i < n - 1; i++) { // ㅜ
		for (int j = 1; j < m - 1; j++) {
			int ans = arr[i][j] + arr[i + 1][j] + arr[i][j - 1] + arr[i][j + 1];
			result = max(result, ans);
		}
	}
	for (int i = 1; i < n - 1; i++) { // ㅓ
		for (int j = 1; j < m; j++) {
			int ans = arr[i][j] + arr[i + 1][j] + arr[i - 1][j] + arr[i][j - 1];
			result = max(result, ans);
		}
	}
	for (int i = 1; i < n - 1; i++) { // ㅏ
		for (int j = 0; j < m - 1; j++) {
			int ans = arr[i][j] + arr[i + 1][j] + arr[i - 1][j] + arr[i][j + 1];
			result = max(result, ans);
		}
	}
}

int main() {
	init();
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visit[i][j] = true;
			DFS(i, j, 1, arr[i][j]);
			visit[i][j] = false;
		}
	}
	DFS_H();
	cout << result << endl;
	return 0;
}
