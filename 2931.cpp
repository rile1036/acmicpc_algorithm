#include<iostream>
#include<vector>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>

using namespace std;


#define MAX 26

// ↑ 0  ↓ 1  ← 2  → 3
int R, C, Direction;
char arr[MAX][MAX];
vector <pair <int, int>> Gas_Start;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void Result(int x, int y) {
	cout << x << " " << y << " ";
	bool Direct_check[4] = { false, };
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i]; int ny = y + dy[i];
		if (nx <= 0 || nx > R || ny <= 0 || ny > C) continue;
		if (arr[nx][ny] != '.') {
			if (i == 0 && (arr[nx][ny] == '|' || arr[nx][ny] == '+' 
                || arr[nx][ny] == '1' || arr[nx][ny] == '4'))
				Direct_check[i] = true;
			else if (i == 1 && (arr[nx][ny] == '|' || arr[nx][ny] == '+' 
                || arr[nx][ny] == '2' || arr[nx][ny] == '3'))
				Direct_check[i] = true;
			else if (i == 2 && (arr[nx][ny] == '-' || arr[nx][ny] == '+' 
                || arr[nx][ny] == '1' || arr[nx][ny] == '2'))
				Direct_check[i] = true;
			else if (i == 3 && (arr[nx][ny] == '-' || arr[nx][ny] == '+'
                || arr[nx][ny] == '3' || arr[nx][ny] == '4'))
				Direct_check[i] = true;
		}
	}

	if (Direct_check[0] && Direct_check[1] && Direct_check[2] && Direct_check[3]) cout << "+";
	else if (Direct_check[0] && Direct_check[1]) cout << "|";
	else if (Direct_check[2] && Direct_check[3]) cout << "-";
	else if (Direct_check[1] && Direct_check[3]) cout << "1";
	else if (Direct_check[0] && Direct_check[3]) cout << "2";
	else if (Direct_check[0] && Direct_check[2]) cout << "3";
	else if (Direct_check[1] && Direct_check[2]) cout << "4";
	return;
}

void DFS(int init_x, int init_y, int Direct) {
	if (arr[init_x][init_y] == '.') {
		Result(init_x, init_y);
		return;
	}

	int nx = init_x + dx[Direct]; int ny = init_y + dy[Direct];

	if (Direct == 0) {
		if (arr[nx][ny] == '|' || arr[nx][ny] == '+') Direct = 0;
		else if (arr[nx][ny] == '1') Direct = 3;
		else if (arr[nx][ny] == '4') Direct = 2;
	}

	else if (Direct == 1) {
		if (arr[nx][ny] == '|' || arr[nx][ny] == '+') Direct = 1;
		else if (arr[nx][ny] == '2') Direct = 3;
		else if (arr[nx][ny] == '3') Direct = 2;
	}

	else if (Direct == 2) {
		if (arr[nx][ny] == '-' || arr[nx][ny] == '+') Direct = 2;
		else if (arr[nx][ny] == '1') Direct = 1;
		else if (arr[nx][ny] == '2') Direct = 0;
	}

	else if (Direct == 3) {
		if (arr[nx][ny] == '-' || arr[nx][ny] == '+') Direct = 3;
		else if (arr[nx][ny] == '3') Direct = 0;
		else if (arr[nx][ny] == '4') Direct = 1;
	}
	DFS(nx, ny, Direct);
	return;
}

void Check_Direction() {
	for (int i = 0; i < 4; i++) {
		int nx = Gas_Start.front().first + dx[i];
		int ny = Gas_Start.front().second + dy[i];

		if (nx <= 0 || nx > R || ny <= 0 || ny > C) continue;
		if (arr[nx][ny] != '.') {
			if (nx == Gas_Start.front().first) {
				if (ny == Gas_Start.front().second - 1)
					Direction = 2;
				else if (ny == Gas_Start.front().second + 1)
					Direction = 3;
			}
			else if (ny == Gas_Start.front().second) {
				if (nx == Gas_Start.front().first - 1)
					Direction = 0;
				else if (nx == Gas_Start.front().first + 1)
					Direction = 1;
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
	cin >> R >> C;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'M')
				Gas_Start.push_back(make_pair(i, j));
		}
	}

	Check_Direction();
	DFS(Gas_Start.front().first, Gas_Start.front().second, Direction);

	return 0;
}