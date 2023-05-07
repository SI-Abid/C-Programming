#include<stdio.h>
int main()
{
    int arr[4][5][6];
    int value = 1;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            for (int k = 0; k < 6; k++)
            {
                arr[i][j][k] = value;
                value++;
            }
        }
    }
    return 0;
}