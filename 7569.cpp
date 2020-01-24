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

#define MAX 101

int N, M, H;
int tomato_day = 0;
int arr[MAX][MAX][MAX];
bool visit[MAX][MAX][MAX];
int dh[6] = { -1, 1, 0, 0, 0, 0 };
int dx[6] = { 0, 0, -1, 1, 0, 0 };
int dy[6] = { 0, 0, 0, 0 , -1, 1 };

queue <pair <pair <int, int>, int>> que;

int BFS() {
	while (!que.empty()) {
		int size = que.size();
		for (int s = 0; s < size; s++) {
			int h = que.front().first.first;
			int x = que.front().first.second;
			int y = que.front().second;

			que.pop();

			for (int i = 0; i < 6; i++) {
				int nh = h + dh[i];
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx < 0 || ny < 0 || nh < 0 || nx >= M || ny >= N || nh >= H) continue;
				if (arr[nh][nx][ny] == 0 && !visit[nh][nx][ny]) {
					arr[nh][nx][ny] = 1;
					visit[nh][nx][ny] = true;
					que.push(make_pair(make_pair(nh, nx), ny));
				}
			}
			if (que.size() == 0)
				return tomato_day;
		}
		tomato_day++;
	}
}

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}

int main() {
	init();
	cin >> N >> M >> H;
	
	for (int h = 0; h < H; h++) {
		for (int x = 0; x < M; x++) {
			for (int y = 0; y < N; y++) {
				cin >> arr[h][x][y];
				if (arr[h][x][y] == 1) {
					que.push(make_pair(make_pair(h, x), y));
					visit[h][x][y] = true;
				}
				if (arr[h][x][y] == -1) {
					visit[h][x][y] = true;
				}
			}
		}
	}
	BFS();
	for (int h = 0; h < H; h++) {
		for (int x = 0; x < M; x++) {
			for (int y = 0; y < N; y++) {
				if (arr[h][x][y] == 0)
					tomato_day = -1;
			}
		}
	}

	cout << tomato_day;
	return 0;
}
