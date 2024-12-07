# strtok_escaped

![CI/CD Status Badge](https://github.com/mofosyne/strtok_escaped.c/actions/workflows/ci.yml/badge.svg)

Tokenise a string from a single char deliminator. This is an alternative to strtok but with escaped character support for deliminating a string with a single char (e.g. csv or psv) 

## install

```sh
$ clib install mofosyne/strtok_escaped.c
```

## usage

```c
char str[512];
strcpy(str, "apple|banana|cherry");
printf("%s", str);
```

## license

GNUv3
