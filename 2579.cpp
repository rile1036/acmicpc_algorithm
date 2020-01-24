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

int testcase;
int DP[305];
int stair_score[305];

int main() {
	cin >> testcase;
	for (int i = 0; i < testcase; i++) cin >> stair_score[i];
	
	DP[0] = stair_score[0];
	DP[1] = max(stair_score[0] + stair_score[1], stair_score[1]);
	DP[2] = max(stair_score[0] + stair_score[2], stair_score[1] + stair_score[2]);

	for (int i = 3; i < testcase; i++) {
		DP[i] = max(DP[i - 2] + stair_score[i], DP[i - 3] + stair_score[i - 1] + stair_score[i]);
	}
	cout << DP[testcase - 1] << endl;

	return 0;
}