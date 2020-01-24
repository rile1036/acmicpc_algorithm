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

int N;

int cal(int num) {
	int sum = 0;
	for (int i = num; i > 0; i = i / 10) {
		int div = i % 10;
		sum += div;
	}
	sum += num;
	return sum;
}

void init() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}

int main() {
	init();
	cin >> N;
		
	for (int i = 1; i <= N; i++) {
		if (cal(i) == N) {
			cout << i << endl;
			return 0;
		}
	}
	cout << 0;
	return 0;
}