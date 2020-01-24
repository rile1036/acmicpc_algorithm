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

int main() {
	int n;
	cin >> n;

	int count = 0;
	
	vector <pair <int, int>> bubble(n);

	for (int i = 0; i < n; i++) {
		cin >> bubble[i].first;
		bubble[i].second = i;
	}

	sort(bubble.begin(), bubble.end());

	for (int i = 0; i < n; i++) {
		if (count < bubble[i].second - i) count = bubble[i].second - i;
	}

	cout << count + 1 << endl;

	return 0;
}