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
int max_area = 0;
int arr[MAX][MAX];
bool visit[MAX][MAX];

int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { -1, 0, 1, 0 };

int BFS(int init_x, int init_y) {
	queue<pair <int, int>> que;
	que.push(make_pair(init_x, init_y));
	visit[init_x][init_y] = true;
	int area_count = 1;

	while (!que.empty()) {
		int x = que.front().first;
		int y = que.front().second;
		que.pop();

		int direct = 1;
		
		for (int i = 0; i < 4; i++) {
			if ((arr[x][y] & direct) == 0) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (0 > nx || 0 > ny || M <= nx || N <= ny) continue;
				if (!visit[nx][ny]) {
					area_count++;
					visit[nx][ny] = true;
					que.push(make_pair(nx, ny));
				}
			}
			direct <<= 1;
		}
	}
	return area_count;
}

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}

int main() {
	init();
	cin >> N >> M;
	
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];
	
	int map_count = 0;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (!visit[i][j]) {
				max_area = max(max_area, BFS(i, j));
				map_count++;
			}
		}
	}
	cout << map_count << "\n" << max_area << "\n";

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			for (int bit = 1; bit <= 8; bit <<= 1) {
				if ((arr[i][j] & bit) != 0) {
					memset(visit, false, sizeof(visit));
					arr[i][j] -= bit;
					max_area = max(max_area, BFS(i, j));
					arr[i][j] += bit;
				}
			}
		}
	}
	cout << max_area << "\n";
	return 0;
}