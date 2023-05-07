#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>
#include<stdbool.h>

#define MAX_NAME 100
#define TABLE_SIZE 13
#define DELETED_NODE (person*)(0xFFFFFFFFFFFFFFFFUL)

typedef struct 
{
    char name[MAX_NAME];
    int age;
} person;

person *table[TABLE_SIZE];

unsigned int hash(char *name)
{
    int length = strnlen(name, MAX_NAME);
    unsigned int hash = 0;
    for (int i = 0; i < length; i++)
    {
        hash = hash * 31 + name[i];
    }
    return hash % TABLE_SIZE;
}

bool init_table()
{
    for(int i = 0; i < TABLE_SIZE; i++)
    {
        table[i] = NULL;
    }
    return true;
}

void print_table()
{
    for(int i=0;i<30;i++)printf("=");
    printf("\n");
    for(int i = 0; i < TABLE_SIZE; i++)
    {
        if(table[i] == NULL)
        {
            printf("\t%i\t-----\n", i);
        }
        else if(table[i] == DELETED_NODE)
        {
            printf("\t%i\t<DELETED>\n", i);
        }
        else
        {
            printf("\t%i\t%s\n", i, table[i]->name);
        }
    }
    for(int i=0;i<30;i++)printf("=");
    printf("\n");
}

bool insert_person(person *p)
{
    if(p==NULL) return false;
    int index = hash(p->name);
    for(int i = 0; i < TABLE_SIZE; i++)
    {
        int try = (index + i) % TABLE_SIZE;
        if(table[try] == NULL || table[try] == DELETED_NODE)
        {
            table[try] = p;
            return true;
        }
    }
    return false;
}

person *lookup(char *name)
{
    int index = hash(name);
    for(int i = 0; i < TABLE_SIZE; i++)
    {
        int try = (index + i) % TABLE_SIZE;
        if(table[try] == NULL)
        {
            return NULL;
        }
        if(table[try] == DELETED_NODE)
        {
            continue;
        }
        if(strcmp(table[try]->name, name) == 0)
        {
            return table[try];
        }
    }
    return NULL;
}

person *delete(char *name)
{
    person *p = lookup(name);
    if(p != NULL)
    {
        int index = hash(name);
        table[index] = DELETED_NODE;
        return p;
    }
    return NULL;
}

int main()
{
    init_table();
    print_table();

    printf("Abid => %u\n", hash("Abid"));
    printf("Saiham => %u\n", hash("Saiham"));
    printf("Habib => %u\n", hash("Habib"));
    printf("Ovi => %u\n", hash("Ovi"));
    printf("Nafisa => %u\n", hash("Nafisa"));
    printf("Sarfaraz => %u\n", hash("Sarfaraz"));
    printf("Mahir => %u\n", hash("Mahir"));
    printf("Zayd => %u\n", hash("Zayd"));
    printf("Mahid => %u\n", hash("Mahid"));

    person Abid = {"Abid", 20};
    person Saiham = {"Saiham", 21};
    person Habiba = {"Habib", 22};
    person Ovi = {"Ovi", 23};
    person Nafisa = {"Nafisa", 14};
    person Sarfaraz = {"Sarfaraz", 15};
    person Mahir = {"Mahir", 16};
    person Zayd = {"Zayd", 5};
    person Mahid = {"Mahid", 6};

    insert_person(&Abid);
    insert_person(&Saiham);
    insert_person(&Habiba);
    insert_person(&Ovi);
    insert_person(&Nafisa);
    insert_person(&Sarfaraz);
    insert_person(&Mahir);
    insert_person(&Zayd);
    insert_person(&Mahid);

    print_table();

    person *p = lookup("Saiham");
    if(p != NULL)
    {
        printf("%s is %i years old\n", p->name, p->age);
    }
    else
    {
        printf("Not found\n");
    }
    p = lookup("Habiba");
    if(p != NULL)
    {
        printf("%s is %i years old\n", p->name, p->age);
    }
    else
    {
        printf("Not found\n");
    }

    p = delete("Abid");

    print_table();
    return 0;
}