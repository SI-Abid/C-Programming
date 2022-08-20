#include<stdio.h>


long long fib(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return fib(n - 1) + fib(n - 2);
}

int main()
{
    printf("100th fibonacci number is %lld\n", fib(100));
    return 0;
}