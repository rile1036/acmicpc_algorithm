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

int A, B, V, Day;

int main() {
	cin >> A >> B >> V;

	Day = (V - B - 1) / (A - B) + 1;
	cout << Day << endl;

	return 0;
}