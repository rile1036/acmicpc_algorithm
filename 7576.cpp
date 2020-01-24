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

#define MAX 1001

int N, M;
int cnt;
int arr[MAX][MAX];
bool visit[MAX][MAX];
int dx[4] = { 1 , -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

queue <pair <pair<int, int>, int>> que;

void BFS() {
	while (!que.empty()) {
		int x = que.front().first.first;
		int y = que.front().first.second;
		cnt = que.front().second;

		que.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= M || ny < 0 || ny >= N)	continue;
			if (arr[nx][ny] == 0 && !visit[nx][ny]) {
				
				visit[nx][ny] = true;
				que.push(make_pair(make_pair(nx, ny), cnt + 1));
			}
		}
	}
}

void check() {
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] == 0 && !visit[i][j]) {
				cnt = -1; break;
			}
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

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) {
				visit[i][j] = true;
				que.push(make_pair(make_pair(i, j), 0));
			}
		}
	}

	BFS();
	check();

	cout << cnt;
	return 0;
}