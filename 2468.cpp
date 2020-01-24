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

#define MAX 101

int N;
int min_value = MAX; int max_value = 0;
int arr[MAX][MAX];
bool visit[MAX][MAX] = { false, };

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

void DFS(int x, int y, int height) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
		if (arr[nx][ny] <= height || visit[nx][ny]) continue;

		visit[nx][ny] = true;
		DFS(nx, ny, height);
	}
}

void init() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}

int main() {
	int result = 1;
	init();
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			min_value = min(min_value, arr[i][j]);
			max_value = max(max_value, arr[i][j]);
		}
	}

	for (int i = min_value; i < max_value; i++) {
		int cnt = 0;
		memset(visit, false, sizeof(visit));
		
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				if (arr[j][k] > i && !visit[j][k]) {
					visit[j][k] = true;
					cnt++;
					DFS(j, k, i);
				}
			}
		}
		result = max(result, cnt);
	}
	cout << result;
	return 0;
}