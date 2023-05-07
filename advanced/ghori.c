// print time in a nice format
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

char segments[7][11][8] = {
    {"┏━┓\0"," ╻ \0","┏━┓\0", "┏━┓\0","╻ ╻\0","┏━┓\0","┏  \0","┏━┓\0","┏━┓\0","┏━┓\0","   \0"},
    {"┃ ┃\0"," ┃ \0","  ┃\0", "  ┃\0","┃ ┃\0","┃  \0","┃  \0","  ┃\0","┃ ┃\0","┃ ┃\0"," ╻ \0"},
    {"┃ ┃\0"," ┃ \0","  ┃\0", "  ┃\0","┃ ┃\0","┃  \0","┃  \0","  ┃\0","┃ ┃\0","┃ ┃\0","   \0"},
    {"┃ ┃\0"," ┃ \0","┏━┛\0", "┣━┫\0","┗━┫\0","┗━┓\0","┣━┓\0","  ┃\0","┣━┫\0","┗━┫\0","   \0"},
    {"┃ ┃\0"," ┃ \0","┃  \0", "  ┃\0","  ┃\0","  ┃\0","┃ ┃\0","  ┃\0","┃ ┃\0","  ┃\0","   \0"},
    {"┃ ┃\0"," ┃ \0","┃  \0", "  ┃\0","  ┃\0","  ┃\0","┃ ┃\0","  ┃\0","┃ ┃\0","  ┃\0"," ╹ \0"},
    {"┗━┛\0"," ╹ \0","┗━━\0", "┗━┛\0","  ╹\0","┗━┛\0","┗━┛\0","  ╹\0","┗━┛\0","┗━┛\0","   \0"},
};

void print_time(char* time_str, int len) {
        // center the time
        puts("");
        puts("");
        puts("");
        puts("");
        puts("");
        puts("");
    for (int i = 0; i < 7; i++) {
            printf("\t\t\t\t");
        for (int j = 0; j < len; j++) {
            for(int k = 0; k < 8; k++) {
                printf("%c", segments[i][time_str[j] - '0'][k]);
            }
            printf(" ");
            // printf("%d ", time_str[j] - '0');
        }
        printf("\n");
    }
}

void ghori()
{

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    int hour = tm.tm_hour;
    int minute = tm.tm_min;
    int second = tm.tm_sec;
    char* time = asctime(&tm);
    char time_str[11];
    sprintf(time_str, "%02d:%02d:%02d", hour, minute, second);
    printf("%s\n", time_str);
    int len = strlen(time_str);
    print_time(time_str, len);
}

int main(void)
{
    while(1) {
        ghori();
        sleep(1);
        system("clear");
    }

    return 0;
}