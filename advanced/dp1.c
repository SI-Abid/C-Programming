#include <stdio.h>
int rec(int n)
{
    if (n == 1 || n == 0)
        return 1;
    if (n == 2)
        return 2;
    return rec(n - 1) + rec(n - 2) + rec(n - 3);
}
signed main()
{
    // how many ways can you make n using 1 2 3
    int n = 33; // cant do more than this
    printf("%d\n", rec(n));
    return 0;
}