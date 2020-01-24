#include<iostream>
#include<queue>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

using namespace std;

#define MAX 10001

int Decimal_Start_num, Decimal_End_num;
int testcase;
bool Decimal_check_num[MAX];
bool visit[MAX];
int DP[MAX];

int change(int num, int site, int change_num) {
	if (site == 0) {
		int temp = num % 1000;
		if (change_num == 0) return -1;
		return change_num * 1000 + temp;
	}
	else if (site == 1) {
		int temp = num % 100;
		return (num / 1000) * 1000 + change_num * 100 + temp;
	}
	else if (site == 2) {
		int temp = num % 10;
		int temp2 = num / 100;
		return (temp2 * 100) + change_num * 10 + temp;
	}
	else if (site == 3) {
		int temp = num / 10;
		return (temp * 10) + change_num;
	}
}

int BFS() {
	queue <int> que;
	que.push(Decimal_Start_num);
	visit[Decimal_Start_num] = true;
	while (!que.empty()) {
		int current_num = que.front();
		que.pop();
		if (current_num == Decimal_End_num) return DP[current_num];
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 10; j++) {
				int next_num = change(current_num, i, j);
				if (next_num == -1) continue;
				if (Decimal_check_num[next_num] && !visit[next_num]) {
					que.push(next_num);
					visit[next_num] = true;
					DP[next_num] = DP[current_num] + 1;
				}
			}
		}
	}
	return -1;
}

void Check_Decimal() {
	memset(Decimal_check_num, true, sizeof(Decimal_check_num));
	Decimal_check_num[0] = Decimal_check_num[1] = false;
	for (int i = 2; i < MAX; i++)
		if (Decimal_check_num[i])
			for (int j = i * i; j < MAX; j += i)
				Decimal_check_num[j] = false;
}

void init() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}

int main() {
	init();
	cin >> testcase;
	
	Check_Decimal();

	while (testcase--) {
		memset(visit, false, sizeof(visit));
		memset(DP, 0, sizeof(DP));
		cin >> Decimal_Start_num >> Decimal_End_num;
		int result = BFS();
		if (result == -1) cout << "Impossible" << endl;
		else cout << result << endl;
	}
	return 0;
}