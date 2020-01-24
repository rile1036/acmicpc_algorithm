#include<iostream>
#include<queue>
#include<vector>
#include<stdlib.h>
#include<math.h>

using namespace std;
#define PI 3.141592653589793238

int main() {
	int R;
	double S1, S2;
	cin >> R;

	S1 = PI * R * R;
	S2 = R * R * 2;
	printf("%.6f\n", S1);
    printf("%.6f\n", S2);
	return 0;
}