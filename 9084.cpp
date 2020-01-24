#include<iostream>
#include<vector>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

using namespace std;

#define MAX 10001

int N, M;
int testcase;
vector <int> vec;
int DP[MAX];

int Solve() {
	for (int i = 0; i < N; i++) 
		for (int j = vec[i]; j <= M; j++)
			DP[j] += DP[j - vec[i]];

	return DP[M];
}

void init() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}

int main() {
	init();
	cin >> testcase;
	
	while (testcase--) {
		cin >> N;

		vec.clear();
		memset(DP, 0, sizeof(DP)); DP[0] = 1;
		for (int i = 0; i < N; i++) {
			int num = 0; cin >> num;
			vec.push_back(num);
		}
		cin >> M;
		cout << Solve() << endl;
	}

	return 0;
}