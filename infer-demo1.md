# Step 1 - Run infer code review

## Description
Infer is a static analysis tool for C/C++, Android/Java and iOS/Objective-C source codes.
See for more : https://fbinfer.com/

## Install infer

Install the infer
```bash
VERSION=0.15.0; \
curl -sSL "https://github.com/facebook/infer/releases/download/v$VERSION/infer-linux64-v$VERSION.tar.xz" \
| sudo tar -C /opt -xJ && \
sudo ln -s "/opt/infer-linux64-v$VERSION/bin/infer" /usr/local/bin/infer
```

## Launch infer :

```bash
make clean && infer -- make
```
You will find 3 bugs in this code: 
 - 2 X Null dereference.
 - 1 X Memory leak

 
 **bug 0:** fail.c:6: error: NULL_DEREFERENCE : pointer `p` last assigned on line 5 could be null and is dereferenced at line 6
 
 **bug 1:** bob.c:7: error:  MEMORY_LEAK:
   - memory dynamically allocated to `bob` by call to `new_person()` at line 6 is not reachable after line 7
   - missing to free.

 **bug 2:** bob.c:7: error: NULL_DEREFERENCE : pointer `bob` last assigned on line 6 could be null and is dereferenced by call to `get_age()`
 
## Explore the first bug

Explore the error traces in Infer reports with inferTraceBugs (for the first bug), launch
```bash
/opt/infer-linux64-v0.15.0/lib/infer/infer/lib/python/inferTraceBugs --select 0
```

## remove the NULL_DEREFERENCE:
Check the pointer because it could cause crashes:
Remove comments in **person.c** on:
```
// if (p == NULL)  { exit(1); }
```

## Remove the memory leak :
Add the free(bob) by replacing in **bob.c**:

```
int age_of_bob()
{
    struct Person *bob = new_person("bob", 32);
    return get_age(bob);
}
```

**by:**

```
int age_of_bob()
{
    struct Person *bob = new_person("bob", 32);
    int ageBob = get_age(bob);
    free(bob);
    return ageBob;
}
```

## remove the second NULL_DEREFERENCE:
Remove the second NULL_DEREFERENCE in **fail.c** by commenting all the function.