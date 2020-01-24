#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

using namespace std;

string Key, Line;

void Solve() {
	int Key_index = 0;
	string result;
	for (int i = 0; i < Line.size(); i++) {
		if (Line[i] == ' ')
			result += ' ';
		else if ((Line[i] - 96) - (Key[Key_index] - 96) <= 0)
			result += (Line[i] - 96) - (Key[Key_index] - 96) + 25 + 'a';
		else if ((Line[i] - 96) - (Key[Key_index] - 96) > 0)
			result += (Line[i] - 96) - (Key[Key_index] - 96) - 1 + 'a';
		
		Key_index += 1;
		if (Key_index == Key.size()) Key_index = 0;
	}
	cout << result;
}

void init() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}

int main() {
	init();
	getline(cin, Line);
	cin >> Key;

	Solve();
	return 0;
}