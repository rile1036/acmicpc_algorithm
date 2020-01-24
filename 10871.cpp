#include<iostream>
#include<queue>
#include<vector>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<string.h>
#include<math.h>
#include<map>
#include<algorithm>

using namespace std;
int main() {
	int n, max, i, a;
	int arr[10001] = { 0, };
	cin >> n >> max;

	for (i = 0; i < n; i++) {
		cin >> arr[i];
		
	}


	for (i = 0; i < n; i++) {
		a = arr[i];
		if (a < max) { printf("%d ", a); }
	}

	return 0;
}