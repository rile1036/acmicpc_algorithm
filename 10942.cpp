#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

#define MAX 2001

int N, M;
int Start, End;
int arr[MAX];
bool DP[MAX][MAX] = { false, };

void Solve() {
        for (int i = 1;i <= N; i++)
               DP[i][i] = true;

        for (int i = 1; i < N; i++)
               if (arr[i] == arr[i + 1])
                       DP[i][i + 1] = true;
    
        for (int i = 2; i < N; i++)
               for (int j = 1; j <= N - i; j++)
                       if (arr[j] == arr[j + i] && DP[j + 1][j + i - 1])
                              DP[j][j + i] = true;
}

int main(void) {
        cin >> N;
        for (int i = 1; i <= N; i++)
               scanf("%d", &arr[i]);

        cin >> M;
        Solve();

        for (int i = 0; i < M; i++) {
               scanf("%d %d", &Start, &End);
               printf("%d\n", DP[Start][End]);
        }
    
        return 0;
}