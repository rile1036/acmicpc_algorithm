#include <iostream>
#include <stdio.h>
using namespace std;
int Max = 0;
int T, N, S, Start, tempStart;
int Num[100], Visit[100], Cnt;
int main() {
	scanf("%d", &T);
	while (T--) {
		for (int i = 0; i<N; i++) Visit[i] = 0;
		scanf("%d %d", &N, &S); Cnt = 0;
		for (int i = 0; i<N; i++) {
			scanf("%d", &Num[i]);
			if (Max < Num[i]) {
				Max = Num[i];
				Start = i;
			}
		}
		Visit[Start] = 1;
		while (1) {
			Cnt++; tempStart = Start; Max = -30000;
			if (Start == S) {
				cout << Cnt << endl;
				break;
			}
			for (int i = tempStart; ;) {
				if (Visit[i] == 0) {
					if (Max < Num[i]) {
						Max = Num[i];
						Start = i;
					}
				}
				i++;
				if (i == N) i = 0;
				if (i == tempStart) break;
			}
			Visit[Start] = 1;
		}
	}
	return 0;
}