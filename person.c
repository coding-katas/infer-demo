#include <stdio.h>
#include <stdlib.h>

struct Person {
    char *name;
    int age;
};

struct Person *new_person(char *name,int age)
{
    struct Person *p = malloc(sizeof(struct Person ));

    // if (p == NULL)  { exit(1); }
    
    if (p != NULL)
    {
        p->name = name;
        p->age = age;
    }
    return p;
}

int get_age(struct Person *p)
{
    return p->age;
}

