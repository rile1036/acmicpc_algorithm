#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <math.h>
#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <string>
#include <string.h>
#include <map>

using namespace std;

#define MAX 1000

#define MAX 1000

int Key[9];
int result = 0;
bool check = false;

int main() {
	for (int i = 0; i < 9; i++) {
		cin >> Key[i];
		result += Key[i];
	}
	for (int i = 0; i < 9; i++) {
		for (int j = i + 1; j < 9; j++) {
			if (result - (Key[i] + Key[j]) == 100) {
				Key[i] = MAX;
				Key[j] = MAX;
				check = true;
				break;
			}
		}
		if (check == true)
			break;
	}

	sort(Key, Key + 9);
	for (int i = 0; i < 7; i++)
		if(Key[i] != MAX)
			cout << Key[i] << endl;

	return 0;
}