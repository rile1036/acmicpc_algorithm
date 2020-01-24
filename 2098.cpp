#include<iostream>
#include<vector>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>

using namespace std;

#define MAX 17
#define INF 987654321

int N;
int City[MAX][MAX];
int DP[1 << MAX][MAX];

int Solve(int visit_city, int current) {
	if (visit_city == (1 << N) - 1) {
		if (City[current][0] != 0) 
			return City[current][0]; 
		return INF; 
	}

	int &result = DP[visit_city][current];
	if (result != -1) return result;
	result = INF;

	for (int i = 0; i < N; i++) {
	
		if (visit_city & (1 << i) || City[current][i] == 0)
			continue;
		result = min(result, City[current][i] + Solve(visit_city | (1 << i), i));
	}

	return result;
}

int main(void) {
	memset(DP, -1, sizeof(DP));
	cin >> N;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> City[i][j];

	cout << Solve(1, 0) << endl;
	return 0;
}