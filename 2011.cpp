#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<string.h>
#include<math.h>
#include<map>
#include<algorithm>

using namespace std;

#define MAX 5001
#define MOD 1000000

int DP[MAX];
string text;

void init() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}

int main() {
	init();
	cin >> text;
	text = "0" + text;

	DP[0] = 1;

	for (int i = 1; i <= text.size(); i++) {
		int num = text[i] - '0';
		if (num > 0 && num <= 9) {
			DP[i] += DP[i - 1]; DP[i] %= MOD;
		}
		
		num = (text[i - 1] - '0') * 10 + (text[i] - '0');
		if (num >= 10 && num <= 26) {
			DP[i] += DP[i - 2];
			DP[i] %= MOD;
		}
	}

	cout << DP[text.size() - 1];

	return 0;
}