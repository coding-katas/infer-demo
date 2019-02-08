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
You found 3 bugs in this code


## Explore first bug

Explore the error traces in Infer reports with inferTraceBugs (for the second bug), launch
```bash
/opt/infer-linux64-v0.15.0/lib/infer/infer/lib/python/inferTraceBugs --select 1
```

## remove second bug
Remove the first bug by adding:
Remove comments on
```

// if (p == NULL)  { exit(1); }
```

## remove Third bug
Remove the Third bug by adding:
Remove comments on
replace:
```
int age_of_bob()
{
    struct Person *bob = new_person("bob", 32);
    return get_age(bob);
}
```

```
int age_of_bob()
{
    struct Person *bob = new_person("bob", 32);
    int ageBob = get_age(bob);
    free(bob);
    return ageBob;
}
```
    