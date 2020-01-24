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

int N, M;
int max_num = 0;
vector <int> vec;

void DFS(int check,int cnt, int sum) {
	if (cnt == 3) {
		if (sum <= M)
			max_num = max(max_num, sum);
		return;
	}

	if (sum > M || check >= N)
		return;

	DFS(check + 1, cnt + 1, sum + vec[check]);
	DFS(check + 1, cnt, sum);
}

void init() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}

int main() {
	init();
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		int num; cin >> num;
		vec.push_back(num);
	}
	
	DFS(0, 0, 0);
	cout << max_num;
	return 0;
}