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

#define MAX 1001

int R, C;
int result = 0;
int start_x, start_y;
int arr[MAX][MAX];
bool flag = false;
bool visit[MAX][MAX];
queue <pair<int, int>> Human;
queue <pair<int, int>> Fire;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

void Fire_BFS(int size) {
	while (size--) { // Fire BFS
		int x = Fire.front().first;
		int y = Fire.front().second;
		Fire.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
			if (arr[nx][ny] == 1) continue;
			arr[nx][ny] = 1;
			Fire.push(make_pair(nx, ny));
		}
	}
}

void Human_BFS(int size) {
	while (size--) {
		int x = Human.front().first;
		int y = Human.front().second;
		Human.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= R || ny < 0 || ny >= C) {
				flag = true;
				return;
			}
			if (visit[nx][ny] || arr[nx][ny] == 1) continue;
			arr[nx][ny] = 2;
			visit[nx][ny] = true;
			Human.push(make_pair(nx, ny));
		}
	}
}

int BFS(int init_x, int init_y) {
	Human.push(make_pair(init_x, init_y));

	while (1) {
		result++;
		int Fire_size = Fire.size();
		int Human_size = Human.size();
		if (Human_size == 0) return -1;
		Fire_BFS(Fire_size);
		Human_BFS(Human_size);
		if (flag) return result;
	}
}

void Map_Setting() {
	for (int i = 0; i < R; i++) {
		string temp; cin >> temp;
		for (int j = 0; j < C; j++) {
			if (temp[j] == '#') arr[i][j] = 1;
			else if (temp[j] == 'J') {
				start_x = i; start_y = j;
				arr[i][j] = 2;
			}
			else if (temp[j] == 'F') {
				Fire.push(make_pair(i, j));
				arr[i][j] = 1;
			}
			else
				arr[i][j] = 0;
		}
	}
}

void init() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}

int main() {
	init();
	cin >> R >> C;
	
	Map_Setting();
	int check = BFS(start_x, start_y);

	if (check == -1) cout << "IMPOSSIBLE";
	else cout << check;
	
	return 0;
}