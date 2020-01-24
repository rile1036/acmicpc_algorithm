#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>

using namespace std;

#define MAX 100001

int Testcase, cnt;
int arr[MAX];
bool visit[MAX], check[MAX];

void DFS(int index) {
	int next_index = arr[index];
	visit[index] = true;

	if (!visit[next_index]) DFS(next_index);
	else 
		if (!check[next_index]) {
			for (int i = next_index; i != index; i = arr[i])
				cnt++;
			cnt++;
		}
	check[index] = true;
}

void Memset_Arr() {
	cnt = 0;
	memset(arr, 0, sizeof(arr));
	memset(visit, false, sizeof(visit));
	memset(check, false, sizeof(check));
}

void init() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}

int main() {
	init();
	cin >> Testcase;
	while (Testcase--) {
		Memset_Arr();
		int N; cin >> N;
		for (int i = 1; i <= N; i++) cin >> arr[i];
		for (int i = 1; i <= N; i++)
			if (!visit[i]) DFS(i);
		cout << N - cnt << endl;
	}
	return 0;
}