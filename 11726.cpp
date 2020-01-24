#include<iostream>
#include<queue>
#include<vector>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<string.h>
#include<math.h>
#include<map>
#include<algorithm>

using namespace std;


int n;
int DP[1001];

int main() {
	cin >> n;
	DP[1] = 1;
	DP[2] = 2;
	for (int i = 3; i <= n; i++)	DP[i] = (DP[i - 1] + DP[i - 2]) % 10007;
	cout << DP[n];
}