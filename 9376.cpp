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

char arr[102][102];
int check[102][102][3];
int h, w;
vector<pair<int, int>> person;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void bfs(int idx)
{
	int x = person[idx].first;
	int y = person[idx].second;
	queue<pair<int, int >> q;
	check[x][y][idx] = 1;
	q.push(make_pair(x, y));

	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int d = 0; d < 4; d++) {
			int nx = x + dx[d];
			int ny = y + dy[d];

			if (nx >= 0 && ny >= 0 && nx <= h + 1 && ny <= w + 1 && arr[nx][ny] != '*' && (check[nx][ny][idx] == 0 || check[nx][ny][idx] > check[x][y][idx])){
				if (arr[nx][ny] == '#' && (check[nx][ny][idx] == 0 || check[nx][ny][idx] > check[x][y][idx] + 1)){
					q.push(make_pair(nx, ny));
					check[nx][ny][idx] = check[x][y][idx] + 1;
				}
				else if (arr[nx][ny] != '#'){
					q.push(make_pair(nx, ny));
					check[nx][ny][idx] = check[x][y][idx];
				}
			}
		}
	}
	return;
}

int main()
{
	int testcase;
	cin >> testcase;

	while(testcase--) {
		cin >> h >> w;
		for (int i = 1; i <= h; i++)
			for (int j = 1; j <= w; j++) {
				cin >> arr[i][j];
				if (arr[i][j] == '$')
					person.push_back(make_pair(i, j));
			}
		person.push_back(make_pair(0, 0));


		int count = 9999;

		for (int i = 0; i < person.size(); i++)
			bfs(i);
		for (int i = 0; i < h + 2; i++) {
			for (int j = 0; j < w + 2; j++) {
				if (check[i][j][0] > 0 && check[i][j][1] > 0 && check[i][j][2] > 0) {
					int tmp = check[i][j][0] + check[i][j][1] + check[i][j][2];
					if (arr[i][j] == '#')
						tmp -= 5;
					else
						tmp -= 3;
					count = min(count, tmp);
				}
				check[i][j][0] = 0;
				check[i][j][1] = 0;
				check[i][j][2] = 0;
				arr[i][j] = 0;
			}
		}

		printf("%d\n", count);
		person.clear();
	}



	return 0;
}