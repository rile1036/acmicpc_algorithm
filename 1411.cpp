#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <vector>

using namespace std;

int N;
int result = 0;
bool Correct;
vector <string> vec;

void check(int index_1, int index_2) {
	if (vec[index_1].size() != vec[index_2].size()) return;
	
	int visit_1[27] = { 0, }, visit_2[27] = { 0, };
	for (int i = 0; i < vec[index_1].size(); i++) {
		int num_1 = vec[index_1][i] - 96; int num_2 = vec[index_2][i] - 96;
		if (!visit_1[num_1] && !visit_2[num_2]) {
			visit_1[num_1] = num_2;
			visit_2[num_2] = num_1;
		}
		else if (visit_1[num_1] != num_2) return;
	}
	Correct = true;
}

void init() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}

int main() {
	init();
	cin >> N;

	for (int i = 0; i < N; i++) {
		string temp; cin >> temp;
		vec.push_back(temp);
	}

	for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j < N; j++) {
			Correct = false;
			check(i, j);
			if (Correct) result++;
		}
	}
	cout << result;
	return 0;
}