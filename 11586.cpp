#include<iostream>
#include<vector>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>

using namespace std;

int N;
int Mental_State;
vector <string> vec;

void Solve(int state) {
	if (state == 1) {
		for (int i = 0; i < vec.size(); i++)
			cout << vec[i] << endl;
		return;
	}
	else if (state == 2) {
		for (int i = 0; i < vec.size(); i++) {
			reverse(vec[i].begin(), vec[i].end());
			cout << vec[i] << endl;
		}
		return;
	}
	else {
		for (int i = vec.size() - 1; i >= 0; i--)
			cout << vec[i] << endl;
		return;
	}
}

void init() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}

int main() {
	init();
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		string s; cin >> s;
		vec.push_back(s);
	}
	cin >> Mental_State;
	
	Solve(Mental_State);
	return 0;
}