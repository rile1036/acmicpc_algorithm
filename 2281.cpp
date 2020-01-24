#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>

using namespace std;

#define MAX 1001
#define MIN 987654321

int N, M;
int Name[MAX];
int DP[MAX][MAX];

int Solve(int index, int length) {
	if (index >= N)
		return 0;

	if (DP[index][length] != -1) return DP[index][length];

	DP[index][length] = MIN;
	DP[index][length] = (M - length + 1) * (M - length + 1) + Solve(index + 1, Name[index] + 1);
	
	if (length + Name[index] <= M)
		DP[index][length] = min(DP[index][length], Solve(index + 1, length + Name[index] + 1));
	
	return DP[index][length];
}

void init() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}

int main() {
	init();
	cin >> N >> M;

	for (int i = 0; i < N; i++)
		cin >> Name[i];

	memset(DP, -1, sizeof(DP));
	cout << Solve(1, Name[0] + 1);
    
	return 0;
}