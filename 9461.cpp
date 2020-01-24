#include<stdio.h>

int main()
{
    int a;
    scanf("%d",&a);
    
    long long t[101] = {0, };
    t[1]= 1;
    t[2]= 1;
    t[3]= 1;
    t[4]= 2;
    t[5]= 2;
    for(int b = 6; b < 101; b++){
        t[b] = t[b-1] + t[b-5];
    }
    long long res[101] = {0,};
    int c;
    for(int i=1; i<=a; i++)
    {
        scanf("%d", &c);
        res[i] = t[c];
    }
    for(int j = 1; j<=a; j++)
        printf("%lld\n",res[j]);
    return 0;
}