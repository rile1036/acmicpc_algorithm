#include<iostream>
#include<queue>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>

using namespace std;


#define MAX 251

int R, C;
int Sheep = 0, Wolf = 0;
char arr[MAX][MAX];
bool visit[MAX][MAX];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int BFS(int init_x, int init_y) {
	queue<pair<int, int>> que;
	que.push(make_pair(init_x, init_y));
	visit[init_x][init_y] = true;
	int Sheep_num = 0;
	int Wolf_num = 0;

	while (!que.empty()) {
		int x = que.front().first;
		int y = que.front().second;
		que.pop();
		
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
			if (arr[nx][ny] == '#' || visit[nx][ny]) continue;

			if (arr[nx][ny] == 'k') {
				Sheep_num += 1;
				que.push(make_pair(nx, ny));
				visit[nx][ny] = true;
			}
			else if (arr[nx][ny] == 'v') {
				Wolf_num += 1;
				que.push(make_pair(nx, ny));
				visit[nx][ny] = true;
			}
			else {
				que.push(make_pair(nx, ny));
				visit[nx][ny] = true;
			}
		}
	}
	if (Sheep_num > Wolf_num)
		Sheep += Sheep_num;
	else
		Wolf += Wolf_num;
	return 0;
}

void init() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}

int main() {
	init();
	cin >> R >> C;
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			cin >> arr[i][j];

	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			if (!visit[i][j]) BFS(i, j);

	cout << Sheep << " " << Wolf;
	return 0;
}