#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

using namespace std;

int testcase;
bool visit[27];

void init() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}

int main() {
	init();
	cin >> testcase;

	int num = 0;
	while (testcase--) {
		memset(visit, false, sizeof(visit));
		string text;
		cin >> text;
		for (int i = 0; i < text.size(); i++) {
			int check = text[i] - 97;
			if (!visit[check]) visit[check] = true;
			else if (visit[check] && check != text[i - 1] - 97)
				break;
			if (i == text.size() - 1) num++;
		}
	}
	cout << num;
	return 0;
}