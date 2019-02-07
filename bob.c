#include <stdlib.h>
#include "person.h"

int age_of_bob()
{
    struct Person *bob = new_person("bob", 32);
    return get_age(bob);
}

int main()
{   
    int age_bob = age_of_bob();
    printf("age of bob: %d\n", age_bob);
    return 0;
}