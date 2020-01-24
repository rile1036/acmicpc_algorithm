#include <iostream>
using namespace std;
int mem[41] = {0, };

int fibo(int n) {
    
    if (mem[n] > 0) return mem[n];
    if (n == 0) return 0;
    if (n == 1 || n == 2) return 1;
    return mem[n] = fibo(n - 2) + fibo(n - 1);
}
 
 
int main() {
    int testcase, num;
    
    cin >> testcase;
 
    for (int i = 0; i < testcase; ++i) {
        cin >> num;
        if (num == 0) cout << "1 0\n";
        else printf("%d %d\n", fibo(num - 1), fibo(num));
    }
 
    return 0;
}