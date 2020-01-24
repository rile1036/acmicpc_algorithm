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


int N, M;
int arr[101][101] = { 0, };
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int bfs(int x, int y) {
	queue <pair <int, int>> que;
	que.push(make_pair(x, y));

	while (!que.empty()) {
		x = que.front().first;
		y = que.front().second;
		que.pop();
        if (arr[N - 1][M - 1] != 1) return arr[N - 1][M - 1] - 1;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx > N - 1 || ny < 0 || ny > M - 1) continue;
			if (arr[nx][ny] == 1){
				que.push(make_pair(nx, ny));
				arr[nx][ny] = arr[x][y] + 1;
			}
		}
	}
}

int main() {
	cin >> N >> M;
	
	for (int i = 0; i < N; i++) {
		string temp;
		cin >> temp;
		for (int j = 0; j < M; j++)	arr[i][j] = temp[j] - '0';
	}
	arr[0][0] = 2;
	cout << bfs(0, 0) << endl;
    
	return 0;
}