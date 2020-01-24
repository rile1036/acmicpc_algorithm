#include<stdio.h>
int n, a[31];

int main(){
    scanf("%d", &n);
    a[0] = a[1] = 1;
    for (int i = 2; i<=n; i++)
    {
        a[i] = a[i-2]*2 + a[i-1];
    }
    printf("%d",(a[n]+a[n/2]+(n%2 == 0) *2*a[n/2 -1])/2);
    return 0;
}