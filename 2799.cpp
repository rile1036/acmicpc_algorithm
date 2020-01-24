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

#define MAX 502

char arr[MAX][MAX];
int M, N;

void Solve() {
	int result_1 = 0, result_2 = 0, result_3 = 0, result_4 = 0, result_5 = 0;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[(i * 5) + 1][(j * 5) + 1] == '*' && arr[(i * 5) + 2][(j * 5) + 1] == '*' && arr[(i * 5) + 3][(j * 5) + 1] == '*' && arr[(i * 5) + 4][(j * 5) + 1] == '*')
				result_5++;
			else if (arr[(i * 5) + 1][(j * 5) + 1] == '*' && arr[(i * 5) + 2][(j * 5) + 1] == '*' && arr[(i * 5) + 3][(j * 5) + 1] == '*')
				result_4++;
			else if (arr[(i * 5) + 1][(j * 5) + 1] == '*' && arr[(i * 5) + 2][(j * 5) + 1] == '*')
				result_3++;
			else if (arr[(i * 5) + 1][(j * 5) + 1] == '*')
				result_2++;
			else
				result_1++;
		}
	}
	cout << result_1 << " " << result_2 << " " << result_3 << " " << result_4 << " " << result_5;
}

void init() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}

int main() {
	init();
	cin >> M >> N;
	for (int i = 0; i < (5 * M) + 1; i++)
		for (int j = 0; j < (5 * N) + 1; j++)
			cin >> arr[i][j];
		
	Solve();
	return 0;
}