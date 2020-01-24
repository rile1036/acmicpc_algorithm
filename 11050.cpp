#include <iostream>
using namespace std;
int fact(int n);
int main(){
    int n,k;
    cin >> n >> k;
    if(k<0 || k>n){
        cout << 0;
    }else{
        cout << fact(n)/(fact(k)*fact(n-k));
    }
}
int fact(int n){
    int mul=1;
    for(int i=n; i>=1; i--){
        mul *= i;
    }
    return mul;
}