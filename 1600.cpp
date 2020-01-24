#include<iostream>
#include<queue>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>

using namespace std;

#define MAX 201

int K;
int N, M;
int arr[MAX][MAX];
bool visit[MAX][MAX][31];

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int knight_dx[8] = { 2, 2, -2, -2, 1, 1, -1, -1 };
int knight_dy[8] = { 1, -1, 1, -1, 2, -2, 2, -2 };

int BFS() {
	queue<pair<pair<int, int>, pair<int, int>>> que;
	que.push(make_pair(make_pair(0, 0), make_pair(0, 0)));
	visit[0][0][0] = true;

	while (!que.empty()) {
		int x = que.front().first.first;
		int y = que.front().first.second;
		int knight = que.front().second.first;
		int cnt = que.front().second.second;
		que.pop();

		if (x == N - 1 && y == M - 1) return cnt;
		if (knight < K) {
			for (int i = 0; i < 8; i++) {
				int nx = x + knight_dx[i];
				int ny = y + knight_dy[i];

				if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
				if (arr[nx][ny] == 0 && !visit[nx][ny][knight + 1]) {
					visit[nx][ny][knight + 1] = true;
					que.push(make_pair(make_pair(nx, ny), make_pair(knight + 1, cnt + 1)));
				}
			}
		}
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
			if (arr[nx][ny] == 0 && !visit[nx][ny][knight]) {
				visit[nx][ny][knight] = true;
				que.push(make_pair(make_pair(nx, ny), make_pair(knight, cnt + 1)));
			}
		}
	}
	return -1;
}

void init() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}

int main() {
	init();
	cin >> K;
	cin >> M >> N;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> arr[i][j];
	
	cout << BFS();
	return 0;
}