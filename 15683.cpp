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

#define MAX 8

int N, M;
int arr[MAX][MAX];
int cctv_cnt = 0;
int result = 100;

vector <pair<pair<int, int>, int>> vec;

void capture(int direct, int x, int y) {
	if (direct == 0) {
		for (int i = x - 1; i >= 0; i--) {
			if (arr[i][y] == 6) break;
			if (arr[i][y] == 0) arr[i][y] = -1;
		}
	}
	else if (direct == 1) {
		for (int i = y + 1; i < M; i++) {
			if (arr[x][i] == 6) break;
			if (arr[x][i] == 0) arr[x][i] = -1;
		}
	}
	else if (direct == 2) {
		for (int i = x + 1; i < N; i++) {
			if (arr[i][y] == 6) break;
			if (arr[i][y] == 0) arr[i][y] = -1;
		}
	}
	else if (direct == 3) {
		for (int i = y - 1; i >= 0; i--) {
			if (arr[x][i] == 6) break;
			if (arr[x][i] == 0) arr[x][i] = -1;
		}
	}
}

void DFS(int cnt) {
	if (cnt == cctv_cnt) {
		int floor = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (arr[i][j] == 0) floor++;
			}
		}
		result = min(result, floor);
		return;
	}

	int x = vec[cnt].first.first;
	int y = vec[cnt].first.second;
	int cctv = vec[cnt].second;

	int arr_copy[MAX][MAX];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			arr_copy[i][j] = arr[i][j];
	
	if (cctv == 1) {
		for (int i = 0; i < 4; i++) {
			capture(i, x, y);
			DFS(cnt + 1);

			for (int i = 0; i < N; i++)
				for (int j = 0; j < M; j++)
					arr[i][j] = arr_copy[i][j];
		}
	}
	else if (cctv == 2) {
		for (int i = 0; i < 2; i++) {
			capture(i, x, y);
			capture(i + 2, x, y);
			DFS(cnt + 1);

			for (int i = 0; i < N; i++)
				for (int j = 0; j < M; j++)
					arr[i][j] = arr_copy[i][j];
		}
	}
	else if (cctv == 3) {
		for (int i = 0; i < 4; i++) {
			capture(i, x, y);
			capture((i + 1) % 4, x, y);
			DFS(cnt + 1);

			for (int i = 0; i < N; i++)
				for (int j = 0; j < M; j++)
					arr[i][j] = arr_copy[i][j];
		}
	}
	else if (cctv == 4) {
		for (int i = 0; i < 4; i++) {
			capture(i, x, y);
			capture((i + 1) % 4, x, y);
			capture((i + 2) % 4, x, y);
			DFS(cnt + 1);

			for (int i = 0; i < N; i++)
				for (int j = 0; j < M; j++)
					arr[i][j] = arr_copy[i][j];
		}
	}
	else if (cctv == 5) {
		for (int i = 0; i < 4; i++) 
			capture(i, x, y);
		DFS(cnt + 1);
	}
}

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] != 0 && arr[i][j] != 6) {
				cctv_cnt++;
				vec.push_back(make_pair(make_pair(i, j), arr[i][j]));
			}
		}
	}

	DFS(0);
	cout << result << endl;

	return 0;
}