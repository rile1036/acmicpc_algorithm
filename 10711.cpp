#include<iostream>
#include<queue>
#include<vector>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

using namespace std;

#define MAX 1001

queue <pair<int, int>> que;
vector <pair<int, int>> vec;
int H, W;
int arr[MAX][MAX];
int check[MAX][MAX] = { 0, };
bool visit[MAX][MAX];

int dx[8] = { 0, 0, -1, 1, -1, -1, 1, 1 };
int dy[8] = { 1, -1, 0, 0, -1, 1, -1, 1 };

int BFS() {
	int result = 0;
	while (!que.empty()) {
		int x = que.front().first; int y = que.front().second;
		que.pop();
		
		for (int i = 0; i < 8; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
			if (visit[nx][ny]) continue;
			if (arr[nx][ny] != 0) 
				check[nx][ny] += 1;
			if (check[nx][ny] >= arr[nx][ny]) {
				vec.push_back(make_pair(nx, ny));
				visit[nx][ny] = true;
			}
		}

		if (que.empty() && vec.size() != 0) {
			result += 1;
			for (int i = 0; i < vec.size(); i++)
				que.push(make_pair(vec[i].first, vec[i].second));
			vec.clear();
		}
	}
	return result;
}

void init() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}

int main() {
	init();
	cin >> H >> W;
	
	for (int i = 0; i < H; i++) {
		string temp; cin >> temp;
		for (int j = 0; j < W; j++) {
			if (temp[j] == '.') {
				arr[i][j] = 0;
				que.push(make_pair(i, j));
				visit[i][j] = true;
			}
			else
				arr[i][j] = temp[j] - '0';
		}
	}
	cout << BFS();
	return 0;
}