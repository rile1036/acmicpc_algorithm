#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

using namespace std;

void init() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}

int main() {
	init();
	string s;
	int JOI_num = 0, IOI_num = 0;
	cin >> s;

	for (int i = 0; i < s.size() - 2; i++) {
		if (s[i] == 'J' && s[i + 1] == 'O' && s[i + 2] == 'I')
			JOI_num++;
		else if (s[i] == 'I' && s[i + 1] == 'O' && s[i + 2] == 'I')
			IOI_num++;
	}
	
	cout << JOI_num << "\n" << IOI_num;
	return 0;
}