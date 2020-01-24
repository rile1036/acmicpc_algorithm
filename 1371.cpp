#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>

using namespace std;


int Alphabet[26];
int MAX_value = 0;

void init() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}

int main() {
	init();
	string Text;
	while (cin >> Text) {
		for (int i = 0; i < Text.size(); i++) {
			if (Text[i] >= 'a' && Text[i] <= 'z')
				Alphabet[Text[i] - 'a']++;
		}
		Text.clear();
	}
	for (int i = 0; i < 26; i++)
		MAX_value = max(MAX_value, Alphabet[i]);

	for (int i = 0; i < 26; i++)
		if (Alphabet[i] == MAX_value) {
			char alpha = 'a' + i;
			cout << alpha;
		}
	return 0;
}