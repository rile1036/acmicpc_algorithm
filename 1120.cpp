#include <iostream>
#include <vector>
#include <stdio.h>
#include <queue>
#include <stack>
#include <algorithm>
#include <stdlib.h>

#define MAX 51

using namespace std;

string A, B;
int result = 50;

int main() {
    cin >> A >> B;
    
    for (int i = 0; i <= B.length() - A.length(); i++){
        int cnt = 0;
        for (int j = 0; j < A.length(); j++){
            if (A[j] != B[i + j]) cnt++;
        }
        result = min(result, cnt);
    }
    
    cout << result << endl;
    return 0;
}
