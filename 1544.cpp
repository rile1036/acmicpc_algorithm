#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <vector>
#include <queue>

using namespace std;

#define MAX 51

int N; int result = 0;
int visit[MAX];
vector <string> vec;

void check(string word) {
	for (int i = 0; i < vec.size(); i++) {
		for (int j = 0; j < word.size(); j++) {
			if (vec[i] == word) return;
			word += word.at(0);
			word.erase(0, 1);
		}
	}
	vec.push_back(word);
}

void init() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}

int main() {
	init();
	cin >> N;
	while (N--) {
		string temp; cin >> temp;
		if (vec.size() == 0)
			vec.push_back(temp);
		else
			check(temp);
	}

	cout << vec.size();

	return 0;
}