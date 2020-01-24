#include<stdio.h>
#include<iostream>
#include<vector>
#include<memory.h>
#include<algorithm>
#include<queue>
using namespace std;
 
#define INF 987654321
int n;
int dp[501][501];
int idx[501];
int sum[501];
 
int solve(int p ,int q)
{
    if(p >= q) return 0;
    if(p+1 == q) return idx[p]+idx[q];
    int & ret = dp[p][q];
    if(ret != INF) return ret;
    
    for(int i=p;i<q;i++){
        ret = min(ret,solve(p,i) + solve(i+1,q) + sum[q] - sum[p-1]);
    }
    return ret;
}
int main()
{
    int test;
    scanf("%d",&test);
 
    for(int t=0;t<test;t++){
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&idx[i]); 
 
        sum[0] = 0;
        for(int i=1;i<=n;i++)
            sum[i] = sum[i-1]+idx[i];
 
        for(int i=1;i<501;i++)
            for(int j=1;j<501;j++)
                dp[i][j] = INF;
        printf("%d\n",solve(1,n));
    }
}

