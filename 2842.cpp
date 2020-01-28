#include<iostream>
#include<vector>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
#include<string.h>

using namespace std;

#define MAX 51

int N;
int Start_x, Start_y;
char arr[MAX][MAX];
int Height[MAX][MAX];
bool visit[MAX][MAX];
vector <int> Height_sort;
vector <pair<int, int>> House;

int dx[8] = { 0, 0, 1, 1, 1, -1, -1, -1 };
int dy[8] = { 1, -1, 0, 1, -1, 0, 1, -1 };

void DFS(int init_x, int init_y, int Left, int Right) {
	int result = 0;
	if (Height[init_x][init_y] < Left || Height[init_x][init_y] > Right) return;
	
	visit[init_x][init_y] = true;

	for (int i = 0; i < 8; i++) {
		int nx = init_x + dx[i];
		int ny = init_y + dy[i];
		if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
		if (Height[nx][ny] < Left || Height[nx][ny] > Right) continue;
		if (visit[nx][ny]) continue;
		visit[nx][ny] = true;
		
		DFS(nx, ny, Left, Right);
	}
}

int Solve() {
	int Left_num = 0, Right_num = 0;
	int answer = 1e9;
	while (1) {
		if (Right_num == Height_sort.size()) break;
		while (1) {
			int check = 0;
			memset(visit, false, sizeof(visit));
			DFS(Start_x, Start_y, Height_sort[Left_num], Height_sort[Right_num]);
			for (int i = 0; i < House.size(); i++)
				if (visit[House[i].first][House[i].second]) {
					check += 1;
				}
			if (check != House.size()) break;
			answer = min(answer, Height_sort[Right_num] - Height_sort[Left_num]);
			Left_num++;
		}
		Right_num++;  
	}

	return answer;
}

void init() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}

int main() {
	init();
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'P') {
				Start_x = i, Start_y = j;
			}
			else if (arr[i][j] == 'K')
				House.push_back(make_pair(i, j));
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> Height[i][j];
			Height_sort.push_back(Height[i][j]);
		}
	}

	sort(Height_sort.begin(), Height_sort.end());
	Height_sort.erase(unique(Height_sort.begin(), Height_sort.end()), Height_sort.end());

	cout << Solve();
	return 0;
}