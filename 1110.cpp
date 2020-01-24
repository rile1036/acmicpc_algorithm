#include<iostream>
#include<queue>
#include<vector>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<string.h>
#include<math.h>
#include<map>
#include<algorithm>

using namespace std;

int main() {
	int n, sum = 0, result = 0;
	int count = 0;
	cin >> n;
	int a = n;

	while (result != a || count == 0) {
		sum = (n / 10) + (n % 10);

		if (sum > 9) {
			sum = sum % 10;
		}

		result = 10 * (n % 10) + sum;
		n = result;
		count++;
	}
	printf("%d\n", count);
}