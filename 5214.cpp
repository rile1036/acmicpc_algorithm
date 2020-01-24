#include<iostream>
#include<queue>
#include<vector>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

#define MAX 100001
#define Station_MAX 101002

int N, K, M;
int Testcase;
int DP[Station_MAX];
vector <int> station[Station_MAX];

int BFS() {
	queue <int> que;
	que.push(1); DP[1] = 1;

	while (!que.empty()) {
		int current_node = que.front();
		que.pop();

		if (current_node == N) return DP[current_node];
		for (int i = 0; i < station[current_node].size(); i++) {
			int next_node = station[current_node][i];
			if (DP[next_node] == 0) {
				que.push(next_node);

				if (next_node > MAX)
					DP[next_node] = DP[current_node];
				else
					DP[next_node] = DP[current_node] + 1;
			}
		}
	}
	return -1;
}

void init() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}

int main() {
	init();
	cin >> N >> K >> M;

	for (int i = 1; i <= M; i++) {
		for (int j = 0; j < K; j++) {
			int station_node; cin >> station_node;
			station[MAX + i].push_back(station_node);
			station[station_node].push_back(MAX + i);
		}
	}

	cout << BFS();
	return 0;
}