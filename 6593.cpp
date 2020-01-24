#include<iostream>
#include<queue>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

using namespace std;

#define MAX 31

int L, R, C;
int Start_x, Start_y, Start_z;
int End_x, End_y, End_z;
char arr[MAX][MAX][MAX];
bool visit[MAX][MAX][MAX];

int dx[6] = { -1, 1, 0, 0, 0, 0 };
int dy[6] = { 0, 0, -1, 1, 0, 0 };
int dz[6] = { 0, 0, 0, 0, -1, 1 };

int BFS() {
	queue <pair<pair<int, int>, pair<int, int>>> que;
	que.push(make_pair(make_pair(Start_x, Start_y), make_pair(Start_z, 0)));
	visit[Start_x][Start_y][Start_z] = true;

	while (!que.empty()) {
		int x = que.front().first.first;
		int y = que.front().first.second;
		int z = que.front().second.first;
		int cnt = que.front().second.second;
		que.pop();

		if (x == End_x && y == End_y && z == End_z) return cnt;

		for (int i = 0; i < 6; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nz = z + dz[i];

			if (nx < 0 || nx >= L || ny < 0 || ny >= R || nz < 0 || nz >= C) continue;
			if (arr[nx][ny][nz] == '#') continue;
			if (arr[nx][ny][nz] == '.' && !visit[nx][ny][nz]) {
				visit[nx][ny][nz] = true;
				que.push(make_pair(make_pair(nx, ny), make_pair(nz, cnt + 1)));
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
	
	while (1) {
		cin >> L >> R >> C;
		memset(arr, false , sizeof(arr));
		memset(visit, false, sizeof(visit));
		if (L == 0 && R == 0 && C == 0) break;
		for (int i = 0; i < L; i++) {
			for (int j = 0; j < R; j++) {
				for (int k = 0; k < C; k++) {
					cin >> arr[i][j][k];
					if (arr[i][j][k] == 'S') {
						Start_x = i; Start_y = j; Start_z = k;
					}
					else if (arr[i][j][k] == 'E') {
						End_x = i; End_y = j; End_z = k;
						arr[i][j][k] = '.';
					}
				}
			}
		}
		int result = BFS();

		if (result == -1) cout << "Trapped!" << endl;
		else cout << "Escaped in " << result << " minute(s)." << endl;
	}
	return 0;
}