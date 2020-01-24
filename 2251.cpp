#include<iostream>
#include<queue>
#include<vector>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>

using namespace std;

#define MAX 202

int A, B, C;
vector <int> water;
bool check[MAX][MAX];

void BFS() {
	queue <pair<pair<int, int>, int>> que;
	que.push(make_pair(make_pair(0, 0), C));

	while (!que.empty()) {
		int check_A = que.front().first.first;
		int check_B = que.front().first.second;
		int check_C = que.front().second;
		que.pop();

		if (check[check_A][check_B]) continue;
		check[check_A][check_B] = true;

		if (check_A == 0) water.push_back(check_C);

		// a -> b
		if (check_A + check_B > B)
			que.push(make_pair(make_pair((check_A + check_B) - B, B), check_C));
		else
			que.push(make_pair(make_pair(0, check_A + check_B), check_C));
		
		// a -> c
		if (check_A + check_C > C)
			que.push(make_pair(make_pair((check_A + check_C) - C, check_B), C));
		else
			que.push(make_pair(make_pair(0, check_B), check_A + check_C));

		// b -> a
		if (check_A + check_B > A)
			que.push(make_pair(make_pair(A, (check_A + check_B) - A), check_C));
		else
			que.push(make_pair(make_pair(check_A + check_B, 0), check_C));

		// b -> c
		if (check_B + check_C > C)
			que.push(make_pair(make_pair(check_A, (check_B + check_C) - C), C));
		else
			que.push(make_pair(make_pair(check_A, 0), check_B + check_C));

		// c -> a
		if (check_A + check_C > A)
			que.push(make_pair(make_pair(A, check_B), (check_A + check_C) - A));
		else
			que.push(make_pair(make_pair(check_A + check_C, check_B), 0));

		// c -> b
		if (check_B + check_C > B)
			que.push(make_pair(make_pair(check_A, B), (check_B + check_C) - B));
		else
			que.push(make_pair(make_pair(check_A, check_B + check_C), 0));
	}
}

void init() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}

int main() {
	init();
	cin >> A >> B >> C;
	BFS();
	sort(water.begin(), water.end());
	
	for (int i = 0; i < water.size(); i++) 
		cout << water[i] << " ";
	
	return 0;
}