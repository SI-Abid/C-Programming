#include <stdio.h>
int dp[100000];
int rec(int n)
{
    if (dp[n] != 0)
        return dp[n];
    if (n == 1 || n == 0)
        return dp[n] = 1;
    if (n == 2)
        return dp[n] = 2;
    return dp[n] = (rec(n - 1) + rec(n - 2) + rec(n - 3)) % 10000007; // answer can be HUGE
}
signed main()
{
    // how many ways can you make n using 1 2 3
    int n = 10000;
    printf("%d\n", rec(n));
    return 0;
}