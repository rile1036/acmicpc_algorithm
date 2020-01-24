#include<iostream>
#include<queue>
#include<vector>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

using namespace std;


#define MAX 51

int N, L, R;
int result = 0;
bool check = true;
int arr[MAX][MAX];
int visit[MAX][MAX];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

void BFS(int init_x, int init_y) {
	int sum = arr[init_x][init_y];
	queue <pair <int, int>> que;
	vector <pair <int, int>> country;
	que.push(make_pair(init_x, init_y));
	country.push_back(make_pair(init_x, init_y));
	visit[init_x][init_y] = true;

	while (!que.empty()) {
		int x = que.front().first;
		int y = que.front().second;
		que.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
			if (visit[nx][ny]|| abs(arr[nx][ny] - arr[x][y]) < L || abs(arr[nx][ny] - arr[x][y]) > R) continue;
			check = true;
			que.push(make_pair(nx, ny));
			country.push_back(make_pair(nx, ny));
			sum += arr[nx][ny];
			visit[nx][ny] = true;
		}
	}
	
	int average = sum / country.size();

	for (int i = 0; i < country.size(); i++) 
		arr[country[i].first][country[i].second] = average;
	country.clear();
}

void init() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}

int main() {
	init();
	cin >> N >> L >> R;
	
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];

	while (check) {
		check = false; result++;
		memset(visit, false, sizeof(visit));

		for (int i = 0; i < N; i++) 
			for (int j = 0; j < N; j++) 
				if (!visit[i][j])
					BFS(i, j);
	}
	cout << result - 1;
	return 0;
}