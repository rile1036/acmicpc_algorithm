#include<stdio.h>

using namespace std;

int n, max_num;
int arr[1001] = { 0, };

int max_fun() {
	for (int j = 0; j < n; j++) {
		if (arr[j] > max_num) {
			max_num = arr[j];
		}
	}
	return max_num;
}

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d",&arr[i]);
	}

	max_fun();

	double result = 0.0;

	for (int a = 0; a < n; a++) {
		result += (double)((arr[a] / (double)max_num)) * 100;
	}

	double ave = result / n;

	printf("%.4lf\n", ave);

	return 0;
}