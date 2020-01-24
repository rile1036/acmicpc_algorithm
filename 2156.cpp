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


int main() {
	int num;
	cin >> num;
	
	int potto[10001];
	int DP[10001];

	for (int i = 0; i < num; i++)	cin >> potto[i];
	
	DP[0] = potto[0];
	DP[1] = max(potto[1] + potto[0], potto[0]);
	
	for (int i = 2; i < num; i++) {
		DP[i] = max(max(DP[i - 1],DP[i - 2] + potto[i]), DP[i - 3] + potto[i - 1] + potto[i]);
	}

	cout << DP[num - 1];
}