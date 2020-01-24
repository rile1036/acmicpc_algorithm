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


int N, K;
bool visit[100001];

int BFS(int N, int K) {
	queue<pair <int, int>> que;
	que.push(make_pair(N, 0));
	visit[N] = true;

	while (!que.empty()) {
		int Line = que.front().first;
		int time = que.front().second;
		que.pop();

		if (Line == K)	return time;

		if (Line + 1 < 100001 && !visit[Line + 1]) {
			que.push(make_pair(Line + 1, time + 1));
			visit[Line + 1] = true;
		}
		if (Line - 1 >= 0 && !visit[Line - 1]) {
			que.push(make_pair(Line - 1, time + 1));
			visit[Line - 1] = true;
		}
		if (Line * 2 < 100001 && !visit[Line * 2]) {
			que.push(make_pair(Line * 2, time + 1));
			visit[Line * 2] = true;
		}
	}
}

int main() {
	cin >> N >> K;
	
	cout << BFS(N, K) << endl;
	return 0;
}