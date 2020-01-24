#include<iostream>
#include<vector>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>

using namespace std;

#define MAX 103

int testcase;
int Shop_num;

int Festival[MAX][MAX];
bool visit[MAX];
bool check = false;
vector <pair<int, int>> vec;

void DFS(int init_x, int END) {
	visit[init_x] = true;
	if (init_x == END) check = true;
	
	for (int i = 0; i < Shop_num + 2; i++) 
		if (Festival[init_x][i] == 1 && !visit[i]) DFS(i, END);	
}

void init() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}

int main() {
	init();
	cin >> testcase;

	while (testcase--) {
		cin >> Shop_num;
        memset(Festival, 0, sizeof(Festival));
		memset(visit, false, sizeof(visit));
		check = false;
		vec.clear();
		
		for (int i = 0; i < Shop_num + 2; i++) {
			int x, y;
			cin >> x >> y;
			vec.push_back(make_pair(x, y));
		}

		for (int i = 0; i < vec.size() - 1; i++) {
			for (int j = 0; j < vec.size(); j++) {
				if ((abs(vec[i].first - vec[j].first) + abs(vec[i].second - vec[j].second)) <= 1000) 
					Festival[i][j] = 1;
			}
		}

		DFS(0, Shop_num + 1);

		if (check) cout << "happy" << endl;
		else cout << "sad" << endl;
	}
	return 0;
}