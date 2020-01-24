#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

using namespace std;

int result = 0;
string Text_Line, Find_Text;

void init() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}

int main() {
	init();
	getline(cin, Text_Line);
	getline(cin, Find_Text);
	if (Text_Line.size() < Find_Text.size()) cout << 0;
	else {
		bool check = false;
		for (int i = 0; i < Text_Line.size(); i++) {
			if (Text_Line[i] == Find_Text[0]) check = true;
			if (check) {
				for (int j = 0; j < Find_Text.size(); j++) {
					if (i + j > Text_Line.size()) break;
					if (Text_Line[i + j] != Find_Text[j]) {
						check = false;
						//i = i + j;
						break;
					}
					if (j == Find_Text.size() - 1) {
						result++;
						i = i + j;
						check = false;
						break;
					}
				}
			}
		}
		cout << result;
	}
	return 0;
}