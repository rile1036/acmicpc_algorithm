#include<iostream>
#include<vector>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

using namespace std;

string Text, Bomb;
vector <char> result;

void init() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}

int main() {
	init();
	cin >> Text >> Bomb;

	for (int i = 0; i < Text.size(); i++) {
		result.push_back(Text[i]);

		if (result.size() < Bomb.size()) continue;
		if (result[result.size() - 1] == Bomb[Bomb.size() - 1]) {
			bool check = true;
			for (int j = 2; j <= Bomb.size(); j++)
				if (result[result.size() - j] != Bomb[Bomb.size() - j])
					check = false;
			if (check)
				result.erase(result.end() - Bomb.size(), result.end());
		}
	}
	
	if (result.size() == 0) cout << "FRULA";
	else
		for (int i = 0; i < result.size(); i++)
			cout << result[i];
	return 0;
}