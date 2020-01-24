#include<iostream>
#include<vector>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>

using namespace std;

#define MAX_COUNT 10001
#define MAX_MONEY 101

int T, K;
int DP[MAX_MONEY][MAX_COUNT];
vector<pair<int, int>> vec;

void init() {
	ios::sync_with_stdio(false);
	cin.tie(0);
}

int main() {
	init();
	cin >> T >> K;
	
	for (int i = 0; i < K; i++) {
		int money, cnt; cin >> money >> cnt;
		vec.push_back(make_pair(money, cnt));
	}
	sort(vec.begin(), vec.end());

	DP[0][0] = 1;
	for (int i = 1; i <= K; i++) {
		for (int j = 0; j <= T; j++) {
			int check_money; int check_cnt;
			if (j / vec[i - 1].first > 0) check_money = DP[i][j - vec[i - 1].first];
			else check_money = 0;
			if (j / vec[i - 1].first > vec[i - 1].second) check_cnt = DP[i - 1][j - vec[i - 1].first * vec[i - 1].second - vec[i - 1].first];
			else check_cnt = 0;
			DP[i][j] = DP[i - 1][j] + check_money - check_cnt;
		}
	}
	cout << DP[K][T];
	return 0;
}