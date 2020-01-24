#include<iostream>
using namespace std;
 
int main() {
    int num;
    int ret1 = 0;
    int ret2 = 0;
 
    cin >> num;
    if (num < 3 || num==4 || num == 7) 
    {
        cout << -1 << endl;
        return 0;
    }
    
    while (num > 0) {
        if (num % 5 == 0) {
            ret1 = num / 5;
            break;
        }
        else {
            num = num - 3;
            ret2++;
        }
    }
    
    cout << ret1 + ret2;
 
}

