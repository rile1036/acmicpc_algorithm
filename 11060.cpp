#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>

using namespace std;

#define MAX 1001
#define MIN 987654321

int N;
int arr[MAX];
int DP[MAX];

int Solve(int index) {
	if (index >= N) return MIN;
	if (index == N - 1) return DP[index] = 0;
	if (DP[index] != -1) return DP[index];
	DP[index] = MIN;

	for (int i = 1; i <= arr[index]; i++)
		DP[index] = min(Solve(index + i) + 1, DP[index]);

	return DP[index];
}

void init() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}

int main() {
	init();
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	
	memset(DP, -1, sizeof(DP));
	int check = Solve(0);
    if (check == MIN) cout << -1;
    else cout << check;
	return 0;
}