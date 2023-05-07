#include<stdio.h>
int main()
{
    printf("Enter 10 numbers: ");
    int a[10], i;
    int sqr[10], sqr_sum = 0;
    int cube[10], cube_sum = 0;
    for (i = 0; i < 10; ++i)
    {
        scanf("%d", &a[i]);
        sqr[i] = a[i] * a[i];
        cube[i] = a[i] * a[i] * a[i];
    }
    for (i = 0; i < 10; ++i)
    {
        sqr_sum += sqr[i];
        cube_sum += cube[i];
    }
    printf("Sum of squares: %d\n", sqr_sum);
    printf("Sum of cubes: %d\n", cube_sum);
    return 0;
}