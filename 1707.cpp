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

#define MAX 20001

int testcase;
int V, E;
vector <int> vec[MAX];
int type_node[MAX];

void DFS(int num, int type) {
	type_node[num] = type;

	for (int i = 0; i < vec[num].size(); i++) {
		int next_node = vec[num][i];
		if (!type_node[next_node]) DFS(next_node, 3 - type); // 1 아니면 2
	}
}

bool check_type() {
	for (int i = 1; i < V; i++) {
		for (int j = 0; j < vec[i].size(); j++) {
			int next_node = vec[i][j];
			if (type_node[i] == type_node[next_node]) 
				return false;
		}
	}
	return true;
}

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}

int main() {
	init();
	cin >> testcase;

	while (testcase--) {
		cin >> V >> E;
		for (int i = 0; i < E; i++) {
			int node_1, node_2;
			cin >> node_1 >> node_2;
			
			vec[node_1].push_back(node_2);
			vec[node_2].push_back(node_1);
		}

		for (int i = 1; i <= V; i++) {
			if (type_node[i] == 0)
				DFS(i, 1);
		}

		if (check_type())
			cout << "YES" << endl;
		else
			cout << "NO" << endl;

		for (int i = 1; i <= V; i++) vec[i].clear();
		memset(type_node, 0, sizeof(type_node));
	}
	return 0;
}