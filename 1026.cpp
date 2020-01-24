#include<iostream>
#include<vector>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>

using namespace std;

int N;
vector<int> vec;
vector<int> cnt;

bool sort(int a, int b) {
	return a > b;
}

void init() {
	ios::sync_with_stdio(false);
	cin.tie(); cout.tie();
}

int main() {
	init();
	cin >> N;
	for (int i = 0; i < N; i++) {
		int vec_cnt; cin >> vec_cnt;
		cnt.push_back(vec_cnt);
	}
	for (int i = 0; i < N; i++) {
		int vec_num; cin >> vec_num;
		vec.push_back(vec_num);
	}
	sort(vec.begin(), vec.end()); sort(cnt.begin(), cnt.end(), greater<int>());
	int sum = 0;
	for (int i = 0; i < N; i++)
		sum += vec[i] * cnt[i];
	cout << sum;
	return 0;
}