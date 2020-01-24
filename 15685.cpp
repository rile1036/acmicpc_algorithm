#include<iostream>
#include<vector>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

#define MAX 101

vector <int> Dragon;
bool visit[MAX][MAX];
int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { 1, 0, -1, 0 };

void Curve(int generation) {
	for (int i = 0; i < generation; i++) {
		vector <int> check; check = Dragon;
		// 0 > 1, 1 > 2, 2 > 3, 3 > 4
		for (int j = check.size() - 1; j >= 0; j--)
			Dragon.push_back((check[j] + 1) % 4);
	}
}

void point_check(int x, int y) {
	visit[x][y] = true;
	for (int i = 0; i < Dragon.size(); i++) {
		x = x + dx[Dragon[i]];
		y = y + dy[Dragon[i]];
		if (x < 0 || x >= MAX || y < 0 || y >= MAX) continue;
		visit[x][y] = true;
	}
}

void init() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}

int main() {
	init();
	int N;
	cin >> N;

	while(N--) {
		int x, y, d, g;
		cin >> y >> x >> d >> g;

		Dragon.clear();
		Dragon.push_back(d);

		Curve(g);
		point_check(x, y);
	}

	int result = 0;
	for (int i = 0; i < MAX - 1; i++)
		for (int j = 0; j < MAX - 1; j++)
			if (visit[i][j] && visit[i + 1][j] && visit[i][j + 1] && visit[i + 1][j + 1])
				result++;

	cout << result;
	return 0;
}