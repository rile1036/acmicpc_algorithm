#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<string.h>
#include<math.h>
#include<map>
#include<algorithm>

using namespace std;

int testcase;
double x, y;

int main() {
	cin >> testcase;
	
	while (testcase--) {
		cin >> x >> y;
		int count = 0;
		double num = 1;
		int distance = y - x;
		
		for (;;num++) {
			if (num * num > y - x) break;
		}

		if ((num - 1) * (num - 1) == y - x) count = 2 * (num - 1) - 1;
		else if ((num - 1) * (num - 1) + ((num * num - (num - 1) * (num - 1)) / 2) >= y - x) count = 2 * num - 2;
		else count = 2 * num - 1;

		cout << count << endl;
	}
	return 0;
}