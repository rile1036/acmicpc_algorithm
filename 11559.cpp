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

char Puyo_arr[12][6];
bool visit[12][6];
queue <pair<int, int>> que;
vector <pair<int, int>> vec;
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0 ,0 };

bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.second < b.second)
		return true;
	else if (a.second == b.second)
	{
		if (a.first < b.first)
			return true;
		return false;
	}
	return false;
}

int BFS() {
	int cnt = 0;
	while (1) {
		vec.clear();
		memset(visit, false, sizeof(visit));
		for (int i = 11; i >= 0; i--) {
			for (int j = 0; j < 6; j++) {
				if (Puyo_arr[i][j] != '.') {
					queue <pair<int, int>> check;
					char color = Puyo_arr[i][j];
					if (visit[i][j]) continue;
					que.push(make_pair(i, j));
					visit[i][j] = true;
					while (!que.empty()) {
						int x = que.front().first;
						int y = que.front().second;
						check.push(make_pair(x, y));
						que.pop();
						for (int i = 0; i < 4; i++) {
							int nx = x + dx[i];
							int ny = y + dy[i];

							if (nx < 0 || nx >= 12 || ny < 0 || ny >= 6) continue;
							if (Puyo_arr[nx][ny] == color && !visit[nx][ny]) {
								que.push(make_pair(nx, ny));
								visit[nx][ny] = true;
							}
						}
					}
					if (check.size() >= 4) {
						while (!check.empty()) {
							vec.push_back(make_pair(check.front().first, check.front().second));
							check.pop();
						}
					}
				}
			}
		}
		if (vec.size() >= 4) {
			sort(vec.begin(), vec.end(), compare);
			for (int i = 0; i < vec.size(); i++) {
				for (int j = vec[i].first; j > 0; j--) {
					Puyo_arr[j][vec[i].second] = Puyo_arr[j - 1][vec[i].second];
				}
				Puyo_arr[0][vec[i].second] = '.';
			}
			cnt++;
		}
		else 
			break;
	}
	return cnt;
}

void init() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}

int main() {
	init();

	for (int i = 0; i < 12; i++) 
		for (int j = 0; j < 6; j++) 
			cin >> Puyo_arr[i][j];
	cout << BFS();
	return 0;
}
