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

int E, S, M;
int year = 1;

int main() {
	cin >> E >> S >> M;
	
	while (1) {
		if ((year - E) % 15 == 0 && (year - S) % 28 == 0 && (year - M) % 19 == 0)
			break;
		year++;
	}

	cout << year;

	return 0;
}