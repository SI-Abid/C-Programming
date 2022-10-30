#include<stdio.h>
int main()
{
    FILE *file;
    file = fopen("file.txt", "w");
    char ch;
    while(1)
    {
        ch = getchar();
        if(ch == EOF)
            break;
        fputc(ch, file);
    }
    fclose(file);
    return 0;
}