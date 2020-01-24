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
	int n;
	cin >> n;

	while (n--) {
		int DP[11] = {0, };
		DP[1] = 1; DP[2] = 2; DP[3] = 4;
		int test;
		cin >> test;
		for (int i = 4; i <= test; i++) DP[i] = DP[i - 3] + DP[i - 2] + DP[i - 1];
		cout << DP[test]<<endl;
	}
	return 0;
}