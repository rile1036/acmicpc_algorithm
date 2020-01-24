#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include <vector>
#include <string>
#include <map>

using namespace std;

int N;
map <string, int> Marathoner;
vector <string> Marathoner_vec;

void Insert_Marathoner() {
	int check = 0;
	for (int i = 0; i < N; i++) {
		string temp; cin >> temp;
		Marathoner[temp]++;
		Marathoner_vec.push_back(temp);
	}
}

void Check_Marathoner() {
	for (int i = 0; i < N - 1; i++) {
		string temp; cin >> temp;
		Marathoner[temp]--;
	}
}

void init() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}

int main() {
	init();
	cin >> N;

	Insert_Marathoner();
	Check_Marathoner();

	for (int i = 0; i < N; i++)
		if (Marathoner[Marathoner_vec[i]] == 1) {
			cout << Marathoner_vec[i];
			break;
		}
	return 0;
}