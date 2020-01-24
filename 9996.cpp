#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

using namespace std;

int N;
string check_Text;
string Front_Text, Back_Text;

void check_Pattern() {
	bool Star = false;
	for (int i = 0; i < check_Text.size(); i++) {
		if (check_Text[i] == '*') Star = true;
		else if (!Star)
			Front_Text += check_Text[i];
		else if (Star)
			Back_Text += check_Text[i];
	}
}

void init() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}

int main() {
	init();
	cin >> N >> check_Text;

	check_Pattern();
	
	for (int i = 0; i < N; i++) {
		string Text; cin >> Text;
		bool Wrong_Check = false;
		for (int j = 0; j < Front_Text.size(); j++) {
			if (Text[j] != Front_Text[j]) {
				Wrong_Check = true;
				break;
			}
		}

		if (!Wrong_Check) {
			int End_size = Text.size() - 1;
			for (int j = Back_Text.size() - 1; j >= 0; j--) {
				if (Text[End_size] != Back_Text[j] || Front_Text.size() - 1 >= End_size) {
					Wrong_Check = true;
					break;
				}
                End_size--;
			}
		}
		
		if (!Wrong_Check)
			cout << "DA\n";
		else 
			cout << "NE\n";
	}
	return 0;
}