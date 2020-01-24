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
#define mod 1000000000

int main() {
	int n;
	int DP[101][10];
	int max_sum = 0;

	cin >> n;

	for (int i = 0; i < 10; i++) DP[1][i] = 1;

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 0)	DP[i][0] = DP[i - 1][1] % mod;
			else if (j == 9) DP[i][9] = DP[i - 1][8] % mod;
			else DP[i][j] = (DP[i - 1][j - 1] + DP[i - 1][j + 1]) % mod;
		}
	}

	for (int i = 1; i < 10; i++)	max_sum = (max_sum + DP[n][i]) % mod;
	cout << max_sum;
	return 0;
}