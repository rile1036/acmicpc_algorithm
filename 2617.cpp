#include<iostream>
#include<vector>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>

using namespace std;

#define MAX 101

int M, N;
int result = 0;
bool check[MAX];
bool visit[2][MAX];
vector <int> Heavy[MAX];
vector <int> Light[MAX];

int DFS(int number, vector <int> vec[MAX], int Row) {
	int Lank = 1;
	for (int i = 0; i < vec[number].size(); i++) {
		if (!visit[Row][vec[number][i]]) {
			visit[Row][vec[number][i]] = true;
			
			Lank += DFS(vec[number][i], vec, Row);
		}
	}
	return Lank;
}

void init() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}

int main() {
	init();
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int Ball_1, Ball_2;
		cin >> Ball_1 >> Ball_2;
		Heavy[Ball_1].push_back(Ball_2);
		Light[Ball_2].push_back(Ball_1);
	}

	for (int i = 1; i <= N; i++) {
		memset(visit, false, sizeof(visit));
		visit[0][i] = visit[1][i] = true;

		int High_Lank = DFS(i, Heavy, 0); 
		int Low_Lank = DFS(i, Light, 1);
		
		if (High_Lank > (N + 1) / 2 || Low_Lank > (N + 1) / 2)
			check[i] = true;
	}

	for (int i = 0; i <= N; i++)
		if (check[i])
			result++;

	cout << result;
	return 0;
}