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

int N;
int person_num1, person_num2;
int relation_count;
vector <int> vec[MAX];
bool visit[MAX];
queue <int> que;
int depth[MAX];

void BFS(int node) {
	visit[node] = true;
	que.push(node);
	
	while (!que.empty()) {
		int start_node = que.front();
		que.pop();
		for (int i = 0; i < vec[start_node].size(); i++) {
			if (!visit[vec[start_node][i]]) {
				visit[vec[start_node][i]] = true;
				depth[vec[start_node][i]] = depth[start_node] + 1;
				que.push(vec[start_node][i]);
			}
		}
	}
}

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}

int main() {
	cin >> N;
	cin >> person_num1 >> person_num2;
	cin >> relation_count;

	while (relation_count--) {
		int point_1, point_2;
		cin >> point_1 >> point_2;
		vec[point_1].push_back(point_2); vec[point_2].push_back(point_1);
	}

	BFS(person_num1);

	if (depth[person_num2] != 0) cout << depth[person_num2] << endl;
	else cout << "-1" << endl;
	return 0;
}