#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

using namespace std;

int Girl_num;
string Boy_name;
string Girl_name;
int Boy_LOVE[4] = { 0, };
int Girl_LOVE[4] = { 0, };
int check = 0;
int Max_check = -1; string ANS_name;

void LOVE_Check(string name, int *LOVE) {
	for (int i = 0; i < name.size(); i++) {
		if (name[i] == 'L') {
			LOVE[0]++;
		}
		else if (name[i] == 'O') {
			LOVE[1]++;
		}
		else if (name[i] == 'V') {
			LOVE[2]++;
		}
		else if (name[i] == 'E') {
			LOVE[3]++;
		}
	}
}

void init() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}

int main(){
	init();
	cin >> Boy_name;
	LOVE_Check(Boy_name, Boy_LOVE);
	cin >> Girl_num;
	while (Girl_num--) {
		memset(Girl_LOVE, 0, sizeof(Girl_LOVE));
		cin >> Girl_name;
		LOVE_Check(Girl_name, Girl_LOVE);
		int L = Boy_LOVE[0] + Girl_LOVE[0];
		int O = Boy_LOVE[1] + Girl_LOVE[1];
		int V = Boy_LOVE[2] + Girl_LOVE[2];
		int E = Boy_LOVE[3] + Girl_LOVE[3];
		check = ((L + O) * (L + V) * (L + E) * (O + V) * (O + E) * (V + E)) % 100;
		if (Max_check < check) {
			Max_check = check; ANS_name = Girl_name;
		}
		else if (Max_check == check) {
			if (ANS_name > Girl_name) ANS_name = Girl_name;
		}
	}
	cout << ANS_name;
	return 0;
}