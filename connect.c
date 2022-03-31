#include <stdio.h>
#include <stdlib.h>

char *connect(char *a, char *b)
{
	char *s = (char*) malloc(100 * sizeof(char));
	int i, j = 0;

	for (i = 0; a[i]!='\0'; ++i)
	{
		s[j++] = a[i];
	}
	
	for (i = 0; b[i]!='\0'; ++i)
	{
		s[j++] = b[i];
	}
	
	s[j]='\0';
	return s;
}

int main(int argc, char const *argv[])
{
	char *first_name = "Saiham";
	char *last_name = " Islam";
	
	char *full_name = connect(first_name, last_name);
	puts(full_name);
	
	return 0;
}