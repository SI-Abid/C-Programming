#include<stdio.h>
#include<time.h>
#include<unistd.h>

int main()
{
    time_t now = time(NULL);    // since Jan 1, 1970
    printf("Time is %ld(sec)\n",now);
    clock_t start = clock();
    long long ans = 0;
    for (size_t i = 0; i < 100000000; i++)
    {
        ans = (i%13)*(i%13)/13*(i%13);
    }
    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time is %f(sec)\n",time_spent);

    return 0;
}