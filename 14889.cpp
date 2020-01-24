#include<iostream>
#include<vector>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>

using namespace std;

#define MAX 21
#define Min_Value 987654321

int N;
int result = Min_Value;
int arr[MAX][MAX];
bool visit[MAX];

void DFS() {
	vector<int> Start; vector<int> Link;

	for (int i = 0; i < N; i++) {
		if (visit[i]) Start.push_back(i);
		else Link.push_back(i);
	}

	int Start_stat = 0; int Link_stat = 0;
	for (int i = 0; i < Start.size() - 1; i++) {
		for (int j = i + 1; j < Start.size(); j++) {
			int Start_x = Start[i]; int Start_y = Start[j];
			int Link_x = Link[i]; int Link_y = Link[j];
			Start_stat += arr[Start_x][Start_y] + arr[Start_y][Start_x];
			Link_stat += arr[Link_x][Link_y] + arr[Link_y][Link_x];
		}
	}

	result = min(result, abs(Start_stat - Link_stat));
	return;
}

void Person_Check(int Person, int num) {
	if (num == N / 2)
		DFS();
	
	for (int i = Person; i < N; i++) {
		if (!visit[i]) {
			visit[i] = true;
			Person_Check(i, num + 1);
			visit[i] = false;
		}
	}
}

void init() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}

int main() {
	init();
	
	cin >> N;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];
	Person_Check(0, 0);

	cout << result;
	return 0;
}