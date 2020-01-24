#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <math.h>
#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <string>
#include <string.h>
#include <map>

using namespace std;

#define MAX 8

int N, M;
int result_count = 0;
int arr[MAX][MAX];
int arr_copy[MAX][MAX];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

vector <pair<int, int>> vec;

int BFS() {
	queue <pair <int, int>> que;
	for (int i = 0; i < vec.size(); i++) que.push(make_pair(vec[i].first, vec[i].second));

	while (!que.empty()) {
		int x = que.front().first;
		int y = que.front().second;
		que.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
			if (arr_copy[nx][ny] == 0) {
				arr_copy[nx][ny] = 2;
				que.push(make_pair(nx, ny));
			}
		}
	}
	int size = 0;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (arr_copy[i][j] == 0) size++;

	result_count = max(size, result_count);
	return result_count;
}

int wall(int cnt) {
	if (cnt == 3) {
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				arr_copy[i][j] = arr[i][j];
	
		return BFS();
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 0) {
				arr[i][j] = 1;
				wall(cnt + 1);
				arr[i][j] = 0;
			}
		}
	}
}

void init() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}

int main() {
	init();
	cin >> N >> M;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2) vec.push_back(make_pair(i, j));
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 0) {
				arr[i][j] = 1;
				wall(1);
				arr[i][j] = 0;
			}
		}
	}

	cout << result_count;
	return 0;
}