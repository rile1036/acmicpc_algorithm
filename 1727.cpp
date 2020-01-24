#include<iostream>
#include<vector>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<algorithm>

using namespace std;

#define MAX 1001

int N, M;
int DP[MAX][MAX];
vector <int> MALE;
vector <int> FEMALE;

int couple() {
	for (int i = 1; i <= MALE.size(); i++) {
		for (int j = 1; j <= FEMALE.size(); j++) {
			DP[i][j] = DP[i - 1][j - 1] + abs(MALE[i - 1] - FEMALE[j - 1]);
			if (i > j)
				DP[i][j] = min(DP[i][j], DP[i - 1][j]);
			if (i < j)
				DP[i][j] = min(DP[i][j], DP[i][j - 1]);
		}
	}
	return DP[N][M];
}

void init() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}

int main() {
	init();
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		int Personality; cin >> Personality;
		MALE.push_back(Personality);
	}
	for (int i = 0; i < M; i++) {
		int Personality; cin >> Personality;
		FEMALE.push_back(Personality);
	}
	sort(MALE.begin(), MALE.end());
	sort(FEMALE.begin(), FEMALE.end());

	cout << couple();
	return 0;
}