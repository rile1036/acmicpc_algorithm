#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int main(void) {
	int num, list;
	int count = 0;
	int map[501][501], marry[501];
	cin >> num >> list;
	for (int i = 0; i < list; i++) {
		int from, to;
		cin >> from >> to;
		map[from][to] = 1, map[to][from] = 1;
		if (from == 1) marry[to] = 1;
		else if (to == 1) marry[from] = 1;
	}
	for (int i = 2; i <= num; i++) {
		if (map[1][i] == 1) {
			for (int j = 2; j <= num; j++) {
				if (map[i][j] == 1) marry[j] = 1;
			}
		}
	}
	for (int i = 2; i <= num; i++) {
		if (marry[i] == 1) count++;
	}
	cout << count << "\n";
	return 0;
}