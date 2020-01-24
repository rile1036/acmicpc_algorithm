#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

#define MAX 41

int N, M;
int DP[MAX];
int result = 1;

int Solve() {
	for (int index = 1; index <= N; index++) {
		if (DP[index] == -1) continue;
		if (DP[index - 1] == -1) {
			DP[index] = 1; continue;
		}
		if (DP[index - 2] == -1 && index > 1) {
			DP[index] = 2; continue;
		}
		DP[index] = DP[index - 1] + DP[index - 2];
	}
	for (int index = 1; index <= N; index++)
		if (DP[index] == -1 && DP[index - 1] != -1)
			result *= DP[index - 1];
	
	if (DP[N] != -1) result *= DP[N];
	return result;
}

void Check() {
	DP[0] = -1;
	for (int i = 1; i <= M; i++) {
		int Vip_num; cin >> Vip_num;
		DP[Vip_num] = -1;
	}
}

void init() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}

int main() {
	init();
	cin >> N >> M;
	
	Check();
	cout << Solve();
	return 0;
}