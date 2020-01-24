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

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}

#define MAX 101
#define MIN_V 999

int N;
int arr[MAX][MAX];
bool check[MAX][MAX];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void DFS(int init_x, int init_y, int num) {
	check[init_x][init_y] = true;
	arr[init_x][init_y] = num;
	
	for (int i = 0; i < 4; i++) {
		int nx = init_x + dx[i];
		int ny = init_y + dy[i];

		if (0 > nx || 0 > ny || N <= nx || N <= ny) continue;
		if (arr[nx][ny] && !check[nx][ny])
			DFS(nx, ny, num);
	}
}

int BFS(int map_num) {
	queue <pair <int, int>> que;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] == map_num) {
				check[i][j] = true;
				que.push(make_pair(i, j));
			}
		}
	}

	int result = 0;

	while (!que.empty()) {
		int size = que.size();
		for (int i = 0; i < size; i++) {
			int x = que.front().first;
			int y = que.front().second;
			que.pop();

			for (int j = 0; j < 4; j++) {
				int nx = x + dx[j];
				int ny = y + dy[j];

				if (0 > nx || 0 > ny || N <= nx || N <= ny) continue;
				if (arr[nx][ny] != 0 && arr[nx][ny] != map_num) return result;
				else if (arr[nx][ny] == 0 && !check[nx][ny]) {
					check[nx][ny] = true;
					que.push(make_pair(nx, ny));
				}
			}
		}
		result++;
	}
}

int main() {
	init();
	cin >> N;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];
	
	int map_num = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!check[i][j] && arr[i][j]) {
				DFS(i, j, map_num);
				map_num++;
			}
		}
	}
	
	int min_value = MIN_V;
	for (int i = 1; i < map_num; i++) {
		memset(check, false, sizeof(check));
		min_value = min(min_value, BFS(i));
	}

	cout << min_value << endl;
	return 0;
}