#include<stdio.h>

int main() {

	int P[50];
	int A[50] = {0, };
    int a, b;
    int num;
	scanf("%d", &num);
	for (a = 0; a < num; a++) {
		scanf("%d", &P[a]);        
		for (b = 0; b < a; b++) {
			if (P[b] > P[a]) {
				A[b]++;
			}
			else if (P[b] <= P[a]) {
				A[a]++;
			}
		}
	}
	for (a = 0; a<num; a++) {
		printf("%d ", A[a]);
	}
	return 0;
}