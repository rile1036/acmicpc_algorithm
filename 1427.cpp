#include<iostream>
#include<queue>
#include<vector>
#include<stdlib.h>
#include<math.h>
#include<algorithm>

using namespace std;

vector<int> arr;

bool desc(int a, int b) {
	return a > b;
}

int main(void){
	int N;
	cin >> N;
	
	while (N) {
		arr.push_back(N % 10);
		N /= 10;
	}

	sort(arr.begin(), arr.end(), desc);
	
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i];
	}

	return 0;
}