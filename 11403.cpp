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

int N;
int arr[MAX][MAX] = { 0, };
bool visit[MAX][MAX] = { false, };

void DFS(int top, int init_x, int init_y) {
	arr[top][init_y] = 1;
	visit[top][init_y] = true;

	for (int i = 1; i <= N; i++) {
		if (!visit[top][i] && arr[init_y][i]) {
			DFS(top, init_y, i);
		}
	}
}

int main() {
	cin >> N;

	for (int i = 1; i <= N; i++) 
		for (int j = 1; j <= N; j++) 
			cin >> arr[i][j];

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (arr[i][j] == 1 && !visit[i][j]) {
				DFS(i, i, j);
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}