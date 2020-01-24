#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <queue>
#include <vector>
#include <string.h>

using namespace std;

#define MAX 51

int n;
char arr[MAX][MAX];
bool visit[MAX][MAX][2];
bool BBB_Shape, EEE_Shape;
pair<int, int> BBB[3], EEE[3], BBB_Center, EEE_Center;

int dx[8] = { -1,-1,-1,0,0,1,1,1 };
int dy[8] = { -1,0,1,-1,1,-1,0,1 };

bool Shape_Turn(int x, int y, int shape) {
	if (shape == 0) { // ㅡ
		for (int i = 0; i < 8; i++) {
			if (i == 3 || i == 4) continue;

			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= n) return false;
			if (arr[nx][ny] == '1') return false;
		}
	}
	else {	// ㅣ
		for (int i = 0; i < 8; i++) {
			if (i == 1 || i == 6) continue;

			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= n) return false;
			if (arr[nx][ny] == '1') return false;
		}
	}
	return true;
}

int BFS(int init_x, int init_y) {
	queue<pair<pair<int, int>, pair<bool, int>>> que;
	que.push(make_pair(make_pair(init_x, init_y), make_pair(BBB_Shape, 0)));
	visit[init_x][init_y][BBB_Shape] = true;

	while (!que.empty()) {
		int x = que.front().first.first;
		int y = que.front().first.second;
		bool shape = que.front().second.first;
		int cnt = que.front().second.second;
		que.pop();

		if (x == EEE_Center.first && y == EEE_Center.second && shape == EEE_Shape)
			return cnt;

		int nx, ny, nnx, nny;
		if (!shape) {
			// cout << "ㅡ";
			// ↑
			nx = x - 1;
			ny = y;
			if (nx >= 0) {
				if (!visit[nx][ny][shape]) {
					if (arr[nx][ny] == '0' && arr[nx][ny - 1] == '0' && arr[nx][ny + 1] == '0') {
						visit[nx][ny][shape] = true;
						que.push(make_pair(make_pair(nx, ny), make_pair(shape, cnt + 1)));
					}
				}
			}

			// ↓
			nx = x + 1;
			ny = y;
			if (nx < n) {
				if (!visit[nx][ny][shape]) {
					if (arr[nx][ny] == '0' && arr[nx][ny - 1] == '0' && arr[nx][ny + 1] == '0') {
						visit[nx][ny][shape] = true;
						que.push(make_pair(make_pair(nx, ny), make_pair(shape, cnt + 1)));
					}
				}
			}

			// ←
			nx = x;
			ny = y - 1;
			nny = y - 2;
			if (nny >= 0) {
				if (!visit[nx][ny][shape]) {
					if (arr[nx][nny] == '0') {
						visit[nx][ny][shape] = true;
						que.push(make_pair(make_pair(nx, ny), make_pair(shape, cnt + 1)));
					}
				}
			}

			// →
			nx = x;
			ny = y + 1;
			nny = y + 2;
			if (nny < n) {
				if (!visit[nx][ny][shape]) {
					if (arr[nx][nny] == '0') {
						visit[nx][ny][shape] = true;
						que.push(make_pair(make_pair(nx, ny), make_pair(shape, cnt + 1)));
					}
				}
			}

			// turn
			if (Shape_Turn(x, y, shape)) {
				if (!visit[x][y][1]) {
					visit[x][y][1] = true;
					que.push(make_pair(make_pair(x, y), make_pair(1, cnt + 1)));
				}
			}
		}

		else {
			// cout << "l";
			// ↑
			nx = x - 1;
			nnx = x - 2;
			ny = y;
			if (nnx >= 0) {
				if (!visit[nx][ny][shape]) {
					if (arr[nnx][ny] == '0') {
						visit[nx][ny][shape	] = true;
						que.push(make_pair(make_pair(nx, ny), make_pair(shape, cnt + 1)));
					}
				}
			}

			// ↓
			nx = x + 1;
			nnx = x + 2;
			ny = y;
			if (nnx < n) {
				if (!visit[nx][ny][shape]) {
					if (arr[nnx][ny] == '0') {
						visit[nx][ny][shape] = true;
						que.push(make_pair(make_pair(nx, ny), make_pair(shape, cnt + 1)));
					}
				}
			}

			// ←
			nx = x;
			ny = y - 1;
			if (ny >= 0) {
				if (!visit[nx][ny][shape]) {
					if (arr[nx][ny] == '0' && arr[nx - 1][ny] == '0' && arr[nx + 1][ny] == '0') {
						visit[nx][ny][shape] = true;
						que.push(make_pair(make_pair(nx, ny), make_pair(shape, cnt + 1)));
					}
				}
			}

			//right
			nx = x;
			ny = y + 1;
			if (ny < n) {
				if (!visit[nx][ny][shape]) {
					if (arr[nx][ny] == '0' && arr[nx - 1][ny] == '0' && arr[nx + 1][ny] == '0') {
						visit[nx][ny][shape] = true;
						que.push(make_pair(make_pair(nx, ny), make_pair(shape, cnt + 1)));
					}
				}
			}

			//turn
			if (Shape_Turn(x, y, shape)) {
				if (!visit[x][y][0]) {
					visit[x][y][0] = true;
					que.push(make_pair(make_pair(x, y), make_pair(0, cnt + 1)));
				}
			}
		}
	}
	return 0;
}

void init() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}

int main() {
	init();
	cin >> n;

	int BBB_index = 0, EEE_index = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'B') {
				arr[i][j] = '0';
				BBB[BBB_index].first = i;
				BBB[BBB_index].second = j;
				BBB_index++;
			}
			else if (arr[i][j] == 'E') {
				arr[i][j] = '0';
				EEE[EEE_index].first = i;
				EEE[EEE_index].second = j;
				EEE_index++;
			}
		}
	}
	
	BBB_Center.first = BBB[1].first;
	BBB_Center.second = BBB[1].second;
	EEE_Center.first = EEE[1].first;
	EEE_Center.second = EEE[1].second;

	if (BBB[0].first == BBB[1].first && BBB[1].first == BBB[2].first)
		BBB_Shape = false; // ㅡ
	else
		BBB_Shape = true; // ㅣ

	if (EEE[0].first == EEE[1].first && EEE[1].first == EEE[2].first)
		EEE_Shape = false; // ㅡ
	else
		EEE_Shape = true; // ㅣ

	cout << BFS(BBB_Center.first, BBB_Center.second);

	return 0;
}