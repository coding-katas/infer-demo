#include <stdlib.h>

int dereference_null()
{
    int *p = 0;
    return *p;
}
