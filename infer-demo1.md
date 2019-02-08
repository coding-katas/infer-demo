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

Run infer :
```bash
make clean && infer -- make
```
You found 3 bugs in this code

Explore the error traces in Infer reports with inferTraceBugs
```bash
/opt/infer-linux64-v0.15.0/lib/infer/infer/lib/python/inferTraceBugs --select 0
```

Remove the first bug by :
```
infer --reactive --make
```


    