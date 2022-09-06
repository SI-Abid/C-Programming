#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* textToMorse(char* text, size_t len)
{
    char* morse = malloc(len*5);
    if(morse==NULL)
    {
        return NULL;
    }
    memset(morse, 0, len*5);
    for(size_t i=0; i<len; i++)
    {
        switch(text[i])
        {
            case 'a':
            case 'A':
                strcat(morse, ".-");
                break;
            case 'b':
            case 'B':
                strcat(morse, "-...");
                break;
            case 'c':
            case 'C':
                strcat(morse, "-.-.");
                break;
            case 'd':
            case 'D':
                strcat(morse, "-..");
                break;
            case 'e':
            case 'E':
                strcat(morse, ".");
                break;
            case 'f':
            case 'F':
                strcat(morse, "..-.");
                break;
            case 'g':
            case 'G':
                strcat(morse, "--.");
                break;
            case 'h':
            case 'H':
                strcat(morse, "....");
                break;
            case 'i':
            case 'I':
                strcat(morse, "..");
                break;
            case 'j':
            case 'J':
                strcat(morse, ".---");
                break;
            case 'k':
            case 'K':
                strcat(morse, "-.-");
                break;
            case 'l':
            case 'L':
                strcat(morse, ".-..");
                break;
            case 'm':
            case 'M':
                strcat(morse, "--");
                break;
            case 'n':
            case 'N':
                strcat(morse, "-.");
                break;
            case 'o':
            case 'O':
                strcat(morse, "---");
                break;
            case 'p':
            case 'P':
                strcat(morse, ".--.");
                break;
            case 'q':
            case 'Q':
                strcat(morse, "--.-");
                break;
            case 'r':
            case 'R':
                strcat(morse, ".-.");
                break;
            case 's':
            case 'S':
                strcat(morse, "...");
                break;
            case 't':
            case 'T':
                strcat(morse, "-");
                break;
            case 'u':
            case 'U':
                strcat(morse, "..-");
                break;
            case 'v':
            case 'V':
                strcat(morse, "...-");
                break;
            case 'w':
            case 'W':
                strcat(morse, ".--");
                break;
            case 'x':
            case 'X':
                strcat(morse, "-..-");
                break;
            case 'y':
            case 'Y':
                strcat(morse, "-.--");
                break;
            case 'z':
            case 'Z':
                strcat(morse, "--..");
                break;
            case '0':
                strcat(morse, "-----");
                break;
            case '1':
                strcat(morse, ".----");
                break;
            case '2':
                strcat(morse, "..---");
                break;
            case '3':
                strcat(morse, "...--");
                break;
            case '4':
                strcat(morse, "....-");
                break;
            case '5':
                strcat(morse, ".....");
                break;  
            case '6':
                strcat(morse, "-....");
                break;
            case '7':
                strcat(morse, "--...");
                break; 
            case '8':
                strcat(morse, "---..");
                break;
            case '9':
                strcat(morse, "----.");
                break;
            case ' ':
                strcat(morse, "_");
                break;
        }
        strcat(morse, "+");
    }
    return morse;
}

int main()
{
    char text[100];
    scanf("%[^\n]", text);
    size_t len = strlen(text);
    char* morse = textToMorse(text, len);
    if(morse==NULL)
    {
        printf("Memory allocation failed");
        return 0;
    }
    puts(morse);
    return 0;
}