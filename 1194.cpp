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
	
#define MAX 51

int N, M;
pair <int, int> start;
char arr[MAX][MAX];
bool visit[MAX][MAX][64];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int BFS(int init_x, int init_y) {
	queue <pair<pair<int, int>, pair<int, int>>> que;
	que.push(make_pair(make_pair(init_x, init_y), make_pair(0, 0)));
	visit[init_x][init_y][0] = true;

	while (!que.empty()) {
		int x = que.front().first.first;
		int y = que.front().first.second;
		int cnt = que.front().second.first;
		int key = que.front().second.second;
		que.pop();

		if (arr[x][y] == '1') return cnt;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
			if (arr[nx][ny] == '#' || visit[nx][ny][key]) continue;
			if (arr[nx][ny] == '.' || arr[nx][ny] == '1' || arr[nx][ny] == '0') {
				visit[nx][ny][key] = true; que.push(make_pair(make_pair(nx, ny), make_pair(cnt + 1, key)));
			}
			else if (arr[nx][ny] >= 'a' && arr[nx][ny] <= 'f') {
				int check_key = key | (1 << (arr[nx][ny] - 97));
				if (!visit[nx][ny][check_key]) {
					visit[nx][ny][key] = true;
					visit[nx][ny][check_key] = true;
					que.push(make_pair(make_pair(nx, ny), make_pair(cnt + 1, check_key)));
				}
			}
			else if (arr[nx][ny] >= 'A' && arr[nx][ny] <= 'F') {
				if (key & 1 << (arr[nx][ny] - 65)) {
					visit[nx][ny][key] = true;
					que.push(make_pair(make_pair(nx, ny), make_pair(cnt + 1, key)));
				}
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
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == '0') {
				start.first = i; start.second = j;
			}
		}
	}

	cout << BFS(start.first, start.second);
	return 0;
}