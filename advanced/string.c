#include<stdio.h>
#include<stdlib.h>

void copy(char *src, char *dest, int *space)
{
    if (*src != '\0')
    {
        *dest = *src;
        if(*src == ' ')
        {
            (*space)++;
        }
        copy(src + 1, dest + 1, space);
    }
}

int main()
{
    char *string;
    string = (char*)malloc(100*sizeof(char));
    printf("Enter a string: ");
    scanf("%[^\n]%*c", string);
    printf("%s\n", string);
    char *string2;
    string2 = (char*)malloc(100*sizeof(char));
    int space_count = 0;
    copy(string, string2, &space_count);
    printf("Copied string: %s\n", string2);
    printf("Space count: %d\n", space_count);
    return 0;
}