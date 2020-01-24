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

int N;
int MAX_value = -1000000001; int MIN_value = 1000000001;
int arr[101];
int oper[4];

void DFS(int plus, int minus, int multy, int div, int sum, int count) {
	if (count == N) {
		MAX_value = max(MAX_value, sum);
		MIN_value = min(MIN_value, sum);
	}

	if (plus > 0)
		DFS(plus - 1, minus, multy, div, sum + arr[count], count + 1);
	if (minus > 0)
		DFS(plus, minus - 1, multy, div, sum - arr[count], count + 1);
	if (multy > 0)
		DFS(plus, minus, multy - 1, div, sum * arr[count], count + 1);
	if (div > 0)
		DFS(plus, minus, multy, div - 1, sum / arr[count], count + 1);
}

void init() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}

int main() {
    init();
	cin >> N;
	for (int i = 0; i < N; i++) 
		cin >> arr[i];
	for (int i = 0; i < 4; i++)
		cin >> oper[i];

	DFS(oper[0], oper[1], oper[2], oper[3], arr[0], 1);

	cout << MAX_value << endl;
    cout << MIN_value << endl;
	return 0;
}