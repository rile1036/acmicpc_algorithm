
#include <stdio.h>
 
#define Max(x, y)        (((x) > (y)) ? (x) : (y))
 
int n;
int cost[1001];
int dp[1001];
 
int solve(int num)
{
    int i;
 
    if (num == 0)    return 0;
    if (dp[num])        return dp[num];
    dp[num] = cost[num];
 
    for (i = 1; i <= num; i++) {
        dp[num] = Max(dp[num], cost[i] + solve(num - i));
    }
 
    return dp[num];
}
 
int main()
{
    int i;
 
    scanf("%d", &n);
 
    for (i = 1; i <= n; i++) {
        scanf("%d", &cost[i]);
    }
 
    printf("%d\n", solve(n));
 
    return 0;
}