#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

int N, M;
int Testcase;
int Current_num, Next_num;

void init() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}

int main() {
	init();
	cin >> Testcase;
	
	while (Testcase--) {
		cin >> N >> M;

		for (int i = 0; i < M; i++) {
			cin >> Current_num >> Next_num;
		}
		cout << N - 1 << endl;
	}
	return 0;
}