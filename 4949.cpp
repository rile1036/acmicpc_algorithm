#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stack>

using namespace std;

void init() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}

int main() {
	init();
	while (1) {
		string Text;
		getline(cin, Text);
		
		if (Text.size() == 1 && Text[0] == '.') break;
		bool check_Line = false;
		stack <char> check;
		for (int i = 0; i < Text.size(); i++) {
			if (Text[i] == '(' || Text[i] == '[')
				check.push(Text[i]);
			else if (Text[i] == ')') {
				if (check.size() > 0 && check.top() == '(')
					check.pop();
				else {
					check_Line = true;
					break;
				}
			}
			else if (Text[i] == ']') {				
				if (check.size() > 0 && check.top() == '[')
					check.pop();
				else {
					check_Line = true;
					break;
				}
			}
		}

		if (check.empty() && !check_Line)
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}
	return 0;
}