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

int arr[21];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int testcase;
	cin >> testcase;
	while (testcase--) {
		string test;
		int test_num;
		cin >> test;
		if (test == "all") {
			for (int i = 0; i < 21; i++) {
				arr[i] = 1;	
			}
		}
		else if (test == "empty") {
			for (int i = 0; i < 21; i++) {
				arr[i] = 0;
			}
		}
		else {
			cin >> test_num;

			if (test == "add") {
				arr[test_num] = 1;
			}
			else if (test == "remove") {
				arr[test_num] = 0;
			}
			else if (test == "check") {
				if (arr[test_num] == 1) printf("1\n"); else printf("0\n");
			}
			else if (test == "toggle") {
				if (arr[test_num] == 1) arr[test_num] = 0; else arr[test_num] = 1;
			}
		}
	}
	return 0;
}