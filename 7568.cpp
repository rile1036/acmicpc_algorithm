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

int N;
int weight, height;
vector <pair<int, int>> vec;


int main() {
	cin >> N;
	int peo_rank[51];
	while (N--) {
		cin >> weight >> height;
		vec.push_back(make_pair(weight, height));
	}

	for (int i = 0; i < vec.size(); i++) {
		int cnt = 1;
		for (int j = 0; j < vec.size(); j++) {
			if ((vec[i].first < vec[j].first) && (vec[i].second < vec[j].second)) {
				cnt++;
			}
		}
		peo_rank[i] = cnt;
	}

	for (int i = 0; i < vec.size(); i++)
		cout << peo_rank[i] << " ";
	

	return 0;
}