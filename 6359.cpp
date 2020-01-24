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

#define MAX 101

int testcase, n;
int result;
bool arr[MAX];

void Solve() {
	for (int i = 1; i <= n; i++)
		for (int j = i; j <= n; j = j + i)
			arr[j] = !arr[j];
}

void Check() {
	for (int i = 1; i <= n; i++)
		if (arr[i]) result += 1;
}

void init() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}

int main() {
	init();
	cin >> testcase;

	while (testcase--) {
		cin >> n;
		result = 0;
		memset(arr, false, sizeof(arr));

		Solve();
		Check();
		cout << result << endl;
	}
	return 0;
}