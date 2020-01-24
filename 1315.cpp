#include<iostream>
#include<stack>
#include<vector>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>

using namespace std;

#define MAX 1001

int N;
bool visit[101];
int DP[MAX][MAX];
vector<pair<pair<int, int>, int>> vec;

int Solve(int STR, int INT) {
	//if (STR <= 0 || STR > 1000 || INT <= 0 || INT > 1000) return 0;
	if (DP[STR][INT] != -1) return DP[STR][INT];

	int point = 0;
	DP[STR][INT] = 0;
	vector <int> check;
	for (int i = 0; i < N; i++) {
		if (vec[i].first.first <= STR || vec[i].first.second <= INT) {
			DP[STR][INT] += 1;
			if (!visit[i]) {
				visit[i] = true;
				check.push_back(i);
				point += vec[i].second;
			}
		}
	}

	for (int i = 0; i <= point; i++) {
		int next_STR = min(STR + i, 1000);
		int next_INT = min(INT + point - i, 1000);
		DP[STR][INT] = max(DP[STR][INT], Solve(next_STR, next_INT));
	}

	for (int i = 0; i < check.size(); i++)
		visit[check[i]] = false;

	return DP[STR][INT];
}

void init() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}

int main() {
	init();
	cin >> N;

	for (int i = 0; i < N; i++) {
		int STR, INT, POINT; cin >> STR >> INT >> POINT;
		vec.push_back(make_pair(make_pair(STR, INT), POINT));
	}
	memset(DP, -1, sizeof(DP));
	cout << Solve(1, 1);
	return 0;
}