#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>

using namespace std;

#define MAX 1001

int T, W;
bool Jadu[2][MAX];
int DP[2][MAX][32];

int check() {
	DP[0][1][0] = Jadu[0][0];
	DP[1][1][1] = Jadu[1][0];

	int result = 0;
	for (int i = 2; i <= T; i++) {
		for (int j = 0; j <= W; j++) {
			DP[0][i][j] = max(DP[0][i - 1][j], DP[1][i - 1][j - 1]) + Jadu[0][i - 1];
			DP[1][i][j] = max(DP[1][i - 1][j], DP[0][i - 1][j - 1]) + Jadu[1][i - 1];

			result = max(result, max(DP[0][i][j], DP[1][i][j]));
		}
	}
	return result;
}

void init() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}

int main() {
	init();
	cin >> T >> W;

	for (int i = 0; i < T; i++) {
		int temp; cin >> temp;
		Jadu[temp - 1][i] = true;
	}

	cout << check();
	return 0;
}