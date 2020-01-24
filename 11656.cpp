#include<iostream>
#include<vector>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>

using namespace std;

void init() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}

int main() {
	string s;
	vector <string> vec;
	cin >> s;
	
	int size = s.size();
	for (int i = 0; i < size; i++) {
		vec.push_back(s);
		s.erase(0, 1);
	}
	
	sort(vec.begin(), vec.end());

	for (int i = 0; i < vec.size(); i++)
		cout << vec[i] << " ";
}