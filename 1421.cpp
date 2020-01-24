#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <vector>

using namespace std;

int N, C, W;
int result = 0;
vector<int> vec;

void init() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}

int main() {
	init();
	cin >> N >> C >> W;

	while (N--) {
		int temp; cin >> temp;
		vec.push_back(temp);
	}
	sort(vec.begin(), vec.end());
	for (int i = 1; i <= vec[vec.size() - 1]; i++) {
		int sum = 0; vector <int> Tree_sum;
		for (int j = 0; j < vec.size(); j++) {
			if (vec[j] % i > 0) {
				int check = W * vec[j] - W * (vec[j] % i) - C * (vec[j] / i);
				Tree_sum.push_back(check);
			}
			else {
				int check = W * vec[j] - C * (vec[j] / i - 1);
				Tree_sum.push_back(check);
			}
		}
		sort(Tree_sum.begin(), Tree_sum.end());
		
		for (int j = Tree_sum.size() - 1; j >= 0; j--) {
			if (sum + Tree_sum[j] < sum) break;
			sum += Tree_sum[j];
		}
		result = max(result, sum);
	}
	cout << result;
	return 0;
}