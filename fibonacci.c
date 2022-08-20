#include <stdio.h>

int memo[101];

int rec(int n)
{
    if(n == 1 || n == 2)
        return memo[n] = n-1;
    if (memo[n] != 0)
    {
        return memo[n];
    }
    return memo[n] = rec(n - 1) + rec(n - 2);

}

int main()
{
    rec(100);
    for (int i = 1; i < 101; i++)
    {
        printf("%d ", memo[i]);
    }
    return 0;
}