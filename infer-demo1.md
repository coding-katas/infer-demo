# Step 1 - Run infer code review

## Description
Infer is a static analysis tool for C/C++, Android/Java and iOS/Objective-C source codes.
See for more : https://fbinfer.com/

## Install infer

Install infer
```bash
VERSION=0.15.0; \
curl -sSL "https://github.com/facebook/infer/releases/download/v$VERSION/infer-linux64-v$VERSION.tar.xz" \
| sudo tar -C /opt -xJ && \
sudo ln -s "/opt/infer-linux64-v$VERSION/bin/infer" /usr/local/bin/infer
```

add bob.c :
```
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
```


add person.h :
```
#include <stdio.h>
#include <stdlib.h>

struct Person *new_person(char *name,int age);
int get_age();
```

add person.c :
```
#include <stdio.h>
#include <stdlib.h>

struct Person {
    char *name;
    int age;
}

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

int get_age()
{
    return p->age;
}
```

add fail.c :
```
#include <stdlib.h>

int dereference_null()
{
    int *p = 0;
    return *p;
}
```

edit Makefile
```
CC=gcc # define the compiler to use
TARGET=runme # define the name of the executable
SOURCES=bob.c person.c fail.c
CFLAGS=-O3
LFLAGS=-lm

# define list of objects
OBJSC=$(SOURCES:.c=.o)
OBJS=$(OBJSC:.cpp=.o)

# the target is obtained linking all .o files
all: $(SOURCES) $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $(TARGET)

purge: clean
	rm -f $(TARGET)

clean:
	rm -f *.o
```

```
make clean 
rm -rf bob.o fail.o person.o
```

trace_bug.sh
```
make clean
infer -- make
```


trace_bug.sh
```
inferTraceBugs --max-level max --select 0
```

rerun infer:
```
infer --reactive --make
```


    