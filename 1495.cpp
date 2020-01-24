#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>

using namespace std;

#define MAX_MUSIC 101
#define MAX_VOLUME 1001

int N, S, M;
int arr[MAX_MUSIC];
int DP[MAX_MUSIC][MAX_VOLUME];

int DP_Music(int index, int volume) {
	if (volume < 0 || volume > M)
		return -2;
	if (index == N) 
		return DP[index][volume] = volume;
	
	if (DP[index][volume] != -1)
		return DP[index][volume];
	
	DP[index][volume] = max(DP_Music(index + 1, volume + arr[index]), DP_Music(index + 1, volume - arr[index]));
	return DP[index][volume];
}

void init() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}

int main() {
	init();
	cin >> N >> S >> M;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	memset(DP, -1, sizeof(DP));
	
	int check = DP_Music(0, S);
	if (check == -2) cout << -1;
	else cout << check;
	return 0;
}