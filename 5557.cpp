#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

using namespace std;

#define MAX 101

int N;
int arr[MAX];
long long DP[MAX][1001];
int result;

long long start_DP(int index, int sum) {
	if (sum < 0 || sum > 20) return 0;
	if (index == N - 2)
	{
		if (sum == result)
			DP[index][sum] = 1;
		else
			DP[index][sum] = 0;
		return DP[index][sum];
	}

	if (DP[index][sum] != -1)
		return DP[index][sum];

	long long check = 0;

	check += start_DP(index + 1, sum + arr[index + 1]);
	check += start_DP(index + 1, sum - arr[index + 1]);

	return DP[index][sum] = check;
}

void init() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}

int main() {
	cin >> N;
	for (int i = 0; i < N - 1; i++)
		cin >> arr[i];
	cin >> result;
	memset(DP, -1, sizeof(DP));
	cout << start_DP(0, arr[0]);
	return 0;
}