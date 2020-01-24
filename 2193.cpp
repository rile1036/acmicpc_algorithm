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

long long int N;
long long int DP[95][2];

int main() {
	cin >> N;
	DP[1][0] = 1;
	DP[1][1] = 1;
	for (int i = 2; i <= N; i++) {
		DP[i][0] = DP[i - 1][0] + DP[i - 1][1];
		DP[i][1] = DP[i - 1][0];
	}
	cout << DP[N][1] << endl;
	return 0;
}