#include<iostream>
#include<queue>
#include<vector>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<string.h>
#include<math.h>
#include<map>
#include<algorithm>

using namespace std;

int testcase;
int length;
int dx[8] = {-1, -2, 1, 2, -1, -2, 1, 2};
int dy[8] = { 2, 1, 2, 1, -2, -1, -2, -1 };
int start[2] = {0, };
int s_end[2] = {0, };
int arr[301][301];
bool visited[301][301];

int BFS(int start_x, int start_y, int count) {
	queue <pair<pair<int, int>, int>> que;
	que.push(make_pair(make_pair(start_x, start_y), count));
	visited[start_x][start_y] = true;

	while (!que.empty()) {
		int x = que.front().first.first;
		int y = que.front().first.second;
		int cnt = que.front().second;
		que.pop();

		if (x == s_end[0] && y == s_end[1]) {
			return cnt;
		}
		for (int i = 0; i < 8; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= length || ny >= length|| visited[nx][ny])
				continue;
			visited[nx][ny] = true;
			que.push(make_pair(make_pair(nx, ny), cnt + 1));
		}
	}
	return 0;
}

int main() {
	cin >> testcase;

	for (int i = 0; i < testcase; i++) {
		cin >> length;
		cin >> start[0] >> start[1];
		cin >> s_end[0] >> s_end[1];

		int value = 0;
		value = BFS(start[0], start[1], 0);
        memset(visited, false, sizeof(visited));
		cout << value << endl;
	}
	return 0;
}