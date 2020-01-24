#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>

using namespace std;

#define MAX 510
#define MIN 987654321

int N;
int arr[MAX][2] = {0, };
int DP[MAX][MAX];

int Func(int Left, int Right) {
	if (Left == Right)
		return 0;

	int min_value = MIN;
	if (DP[Left][Right] != -1) return DP[Left][Right];
	for (int i = Left; i < Right; i++)
		min_value = min(min_value, Func(Left, i) + Func(i + 1, Right) + (arr[Left][0] * arr[i][1] * arr[Right][1]));

	DP[Left][Right] = min_value;
	return DP[Left][Right];
}

void init() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < 2; j++)
			cin >> arr[i][j];
	memset(DP, -1, sizeof(DP));
	cout << Func(0, N - 1);

	return 0;
}