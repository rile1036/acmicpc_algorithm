#include<iostream>
#include<queue>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

using namespace std;

#define MAX 1001

int People_x, People_y;
int testcase;
int W, H;
int arr[MAX][MAX];
bool visit[MAX][MAX];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
queue <pair<int, int>> Fire;

int BFS(int init_x, int init_y) {
	queue<pair<int, int>> que;
	que.push(make_pair(init_x, init_y));

	int result = 0;
	while (1) {
		result++;
		int fire_size = Fire.size();
		while (fire_size--) {
			int fire_x = Fire.front().first;
			int fire_y = Fire.front().second;
			Fire.pop();

			for (int i = 0; i < 4; i++) {
				int nx = fire_x + dx[i];
				int ny = fire_y + dy[i];

				if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
				if (arr[nx][ny] == 1) continue;
				arr[nx][ny] = 1;
				Fire.push(make_pair(nx, ny));
			}
		}

		int people_size = que.size();
		if (people_size == 0) return -1;
		while (people_size--) {
			int x = que.front().first;
			int y = que.front().second;
			que.pop();

			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx < 0 || nx >= H || ny < 0 || ny >= W) return result;
				if (visit[nx][ny] || arr[nx][ny] == 1) continue;
				arr[nx][ny] = 2;
				visit[nx][ny] = true;
				que.push(make_pair(nx, ny));
			}
		}
	}
}

void Memset_ARR() {
	memset(arr, 0, sizeof(arr));
	memset(visit, false, sizeof(visit));
	while (!Fire.empty()) 
		Fire.pop();
}

void init() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}

int main() {
	init();
	
	cin >> testcase;
	while (testcase--) {
		Memset_ARR();
		cin >> W >> H;

		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				char temp; cin >> temp;
				if (temp == '#') arr[i][j] = 1;
				else if (temp == '*') {
					arr[i][j] = 1;
					Fire.push(make_pair(i, j));
				}
				else if (temp == '@') {
					People_x = i; People_y = j;
					arr[i][j] = 2;
				}
				else
					arr[i][j] = 0;
			}
		}

		int check = BFS(People_x, People_y);
		if (check == -1) cout << "IMPOSSIBLE" << endl;
		else cout << check << endl;
	}
	return 0;
}