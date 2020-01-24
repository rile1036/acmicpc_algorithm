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

char arr[MAX][MAX];
bool visit[MAX][MAX];
bool Key[26];
int testcase;
int h, w;
int Document_count;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

void BFS() {
	queue<pair<int, int>> que;
	que.push(make_pair(0, 0));
	visit[0][0] = true;

	while (!que.empty()) {
		int x = que.front().first;
		int y = que.front().second;
		que.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx > h + 1 || ny < 0 || ny > w + 1) continue;
			if (visit[nx][ny] || arr[nx][ny] == '*') continue;
			if ((arr[nx][ny] >= 'A' && arr[nx][ny] <= 'Z') && Key[arr[nx][ny] - 65]) continue;
			visit[nx][ny] = true;
			if (arr[nx][ny] == '$') {
				Document_count++;
				arr[nx][ny] = '.';
			}
			if (arr[nx][ny] >= 'a' && arr[nx][ny] <= 'z') {
				Key[arr[nx][ny] - 97] = false;
				arr[nx][ny] = '.';
				memset(visit, false, sizeof(visit));

				while (!que.empty()) que.pop();
			}
			que.push(make_pair(nx, ny));
		}
	}
}

void Memset_arr() {
	Document_count = 0;
	memset(arr, '.', sizeof(arr));
	memset(visit, false, sizeof(visit));
	memset(Key, false, sizeof(Key));
}

void init() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}

int main() {
	init();	
	cin >> testcase;

	while (testcase--) {
		Memset_arr();
		cin >> h >> w;
		
		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++) {
				cin >> arr[i][j];
				if (arr[i][j] >= 'A' && arr[i][j] <= 'Z')
					Key[arr[i][j] - 65] = true;
			}
		}
		string Have_key; cin >> Have_key;
		if (Have_key != "0")
			for (int i = 0; i < Have_key.size(); i++)
				Key[Have_key[i] - 97] = false;

		BFS();
		cout << Document_count << endl;
	}
	return 0;
}