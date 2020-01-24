#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>

using namespace std;

#define MAX 301

int N, M;
int DP[MAX];

void init() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}

int main() {
	cin >> N >> M;
	DP[0] = N - 1;

	for (int i = 1; i < M; i++) 
		DP[i] = DP[i - 1] + N;
	
	cout << DP[M - 1];
	return 0;
}