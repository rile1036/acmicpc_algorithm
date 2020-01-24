#include<iostream>
#include<stack>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

using namespace std;

int N;
int result = 0;

void init() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}

int main() {
	init();
	cin >> N;

	while (N--) {
		string Line; cin >> Line;
		stack <char> check;
		check.push('TEXT');
		for (int i = 0; i < Line.size(); i++) {
			if (check.top() == Line[i])
				check.pop();
			else
				check.push(Line[i]);
		}
		if (check.size() == 1) result++;
	}
	cout << result;
	return 0;
}