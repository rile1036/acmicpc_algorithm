#include<iostream>
#include<queue>
#include<vector>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<string.h>
#include<math.h>
#include<algorithm>

using namespace std;


bool compare(string a, string b) {
	if (a.length() == b.length()) return (a < b);
	else return a.length() < b.length();
}

int main() {
	int N;
	string input[20001];

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> input[i];
	}

	sort(input, input + N, compare);

	for (int i = 0; i < N; i++) {
		if (input[i] == input[i - 1] && i != 0) continue;
		cout << input[i] << endl;
	}
	return 0;
}