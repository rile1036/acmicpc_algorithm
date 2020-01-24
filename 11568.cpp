#include<iostream>
#include<vector>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<algorithm>

using namespace std;

int N;

vector <int> vec;
vector <int> DP;

void init() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}

int main() {
	init;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int temp; cin >> temp;
		vec.push_back(temp);
	}
	DP.push_back(1);

	for (int i = 1; i < N; i++) {
		DP.push_back(1);
		for (int j = i; j >= 0; j--) 
			if (vec[j] < vec[i]) {
				DP[i] = max(DP[i], DP[j] + 1);
			}
	}
	sort(DP.begin(), DP.end(), greater<int>());
	cout << DP[0];

	return 0;
}