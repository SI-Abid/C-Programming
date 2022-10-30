#include<stdio.h>
int main()
{
    FILE *file;
    file = fopen("file.txt", "r");
    char ch;
    while((ch = fgetc(file)) != EOF)
    {
        printf("%c", ch);
    }
    fclose(file);
    return 0;
}