#include<stdio.h>
#include<stdlib.h>

#define BUFSIZE 25000

int main(int argc, char **argv)
{
    int ret;
    FILE *fp;

    if(argc<2)
    {
        printf("Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    fp = fopen(argv[1], "r");
    if(fp==NULL)
    {
        perror("fopen");
        return EXIT_FAILURE;
    }

    char buf[BUFSIZE];
    ret = fread(buf, sizeof(char), BUFSIZE, fp);
    fclose(fp);

    if(ret>0)
    {
        printf("Got %d bytes from %s\n", ret, argv[1]);
    }
    else
    {
        printf("READ FAILED\n");
        return EXIT_FAILURE;
    }
    
    return EXIT_SUCCESS;
}