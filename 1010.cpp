#include<iostream>
#include<queue>
#include<vector>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<string.h>
#include<math.h>
#include<map>
#include<algorithm>

using namespace std;

int main() {
	int T, N, M;
	cin >> T;

	for (int testCase = 0; testCase < T; testCase++) {
		cin >> N >> M;

		int dp[31][31] = { 0 };

		for (int m = 1; m <= M; m++)
			dp[1][m] = m;

		for (int n = 2; n <= N; n++) {
			for (int m = 1; m <= M; m++) {
				for (int k = n - 1; k < m; k++)
					dp[n][m] += dp[n - 1][k];
			}
		}

		printf("%d\n", dp[N][M]);
	}
	return 0;
}