#include<iostream>
#include<vector>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>

using namespace std;

int R, C;
vector<pair<int, int>> Race_vec;
vector<pair<int, int>> Race_rank;

void init() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}

int main() {
	init();
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		string Race; cin >> Race;
		for (int j = Race.size() - 1; j >= 0; j--) {
			if (Race[j] >= '1' && Race[j] <= '9') {
				Race_vec.push_back(make_pair(j, Race[j] - '0'));
				break;
			}
		}
	}
	sort(Race_vec.begin(), Race_vec.end(), greater<pair<int, int>>());

	int Rank = 1; int check_num = Race_vec[0].first;
	Race_rank.push_back(make_pair(Race_vec[0].second, Rank));
	for (int i = 1; i < Race_vec.size(); i++) {
		if (check_num == Race_vec[i].first)
			Race_rank.push_back(make_pair(Race_vec[i].second, Rank));
		else {
			Rank += 1;
			Race_rank.push_back(make_pair(Race_vec[i].second, Rank));
			check_num = Race_vec[i].first;
		}
	}
	sort(Race_rank.begin(), Race_rank.end());
    
	for (int i = 0; i < Race_rank.size(); i++)
		cout << Race_rank[i].second << endl;
    
	return 0;
}