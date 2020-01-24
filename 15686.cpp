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

#define MAX 51
#define INF 100000001

int N, M;
int result;
int arr[MAX][MAX];
bool visit[14];

vector <pair<int, int>> house;
vector <pair<int, int>> chicken;

void DFS(int idx, int cnt) {
	if (idx > chicken.size()) return;

	if (cnt == M) {
		int cmp_dis = 0;
		for (int i = 0; i < house.size(); i++) {
			int dist = INF;
			for (int j = 0; j < chicken.size(); j++) {
				if (visit[j]) {
					int house_x = house[i].first; int house_y = house[i].second;
					int chicken_x = chicken[j].first; int chicken_y = chicken[j].second;
					int distance = abs(house_x - chicken_x) + abs(house_y - chicken_y);
					dist = min(dist, distance);
				}
			}
			cmp_dis += dist;
		}
		result = min(result, cmp_dis);
		return;
	}

	visit[idx] = true;
	DFS(idx + 1, cnt + 1);
	visit[idx] = false;
	DFS(idx + 1, cnt);
}

void init() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}

int main() {
	init();
	cin >> N >> M;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) house.push_back(make_pair(i, j));
			else if (arr[i][j] == 2) chicken.push_back(make_pair(i, j));
		}
	}
	result = INF;

	DFS(0, 0);
	cout << result << endl;
	return 0;
}