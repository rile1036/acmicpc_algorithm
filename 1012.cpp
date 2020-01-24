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

#define MAX 51

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int arr[MAX][MAX] = { 0, };
bool visit[MAX][MAX] = { false, };
int testcase;
int N, M, num;

void DFS(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
		if (arr[nx][ny] == 1 && !visit[nx][ny]) {
			visit[nx][ny] = true;
			DFS(nx, ny);
		}
	}
}

void init() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}

int main() {
	init();
	cin >> testcase;
	
	while (testcase--) {
		int cnt = 0;
		memset(arr, 0, sizeof(arr));
		memset(visit, false, sizeof(visit));
		cin >> N >> M >> num;
		for (int i = 0; i < num; i++) {
			int x, y;
			cin >> y >> x;
			arr[x][y] = 1;
		}

		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				if (arr[i][j] == 1 && !visit[i][j]) {
					cnt++;
					visit[i][j] = true;
					DFS(i, j);
				}
			}
		}

		cout << cnt << endl;
	}
	return 0;
}