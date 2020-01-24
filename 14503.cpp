#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>

using namespace std;

#define MAX 51

int N, M;
int r, c, d;
int arr[MAX][MAX];
int result = 0;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };


int Direct_Check(int direct) {
	if (direct == 0) return 3;
	else return direct - 1;
}

void DFS(int x, int y, int Direction) {
	if (arr[x][y] == 1) return;

	if (arr[x][y] == 0) {
		arr[x][y] = 2;
		result++;
	}
	// 0 > 3, 1 > 0, 2 > 1, 3 > 2
	for (int i = 0; i < 4; i++) {
		int next_D = Direct_Check(Direction);
		int nx = x + dx[next_D]; int ny = y + dy[next_D];

		if (arr[nx][ny] == 0) {
			DFS(nx, ny, next_D);
			return;
		}
		else {
			Direction = next_D;
		}
	}
	// 네방향 청소 끝, 뒤로 후진
	DFS(x - dx[Direction], y - dy[Direction], Direction);
}

void init() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}

int main() {
	init();

	cin >> N >> M;
	cin >> r >> c >> d;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> arr[i][j];
	
	DFS(r, c, d);
	cout << result << endl;
	return 0;
}