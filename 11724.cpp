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

#define MAX 1001

int N, M;
int map_count = 0;
vector <int> vec[MAX];
bool visit[MAX];

void DFS(int node) {
	visit[node] = true;

	for (int i = 0; i < vec[node].size(); i++) {
		int next = vec[node][i];
		if (visit[next] == false) DFS(next);
	}
}

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}

int main() {
	init();
	cin >> N >> M;

	while (M--) {
		int u, v;
		cin >> u >> v;
		vec[u].push_back(v); vec[v].push_back(u);
	}

	for (int i = 1; i <= N; i++) {
		if (visit[i] == false) {
			DFS(i);
			map_count++;
		}
	}

	cout << map_count << endl;
	return 0;
}