# strtok_escaped

![CI/CD Status Badge](https://github.com/mofosyne/strtok_escaped.c/actions/workflows/ci.yml/badge.svg)

Tokenise a string from a single char deliminator. This is an alternative to strtok but with escaped character support for deliminating a string with a single char (e.g. csv or psv) 

## install

```sh
$ clib install mofosyne/strtok_escaped.c
```

## usage

```c
// Non Reentrant
char *str = "apple|banana|cherry";
char *token = strtok_escaped(str, delim);
while (token != NULL) {
    printf("%s\n", token);
    token = strtok_escaped(NULL, delim);
}
```

```c
// Reentrant
char *str = "apple|banana|cherry";
char *last_token_end = NULL;
while (0)
{
    const char *token = strtok_escaped_r(last_token_end, str, delim);
    if (token == NULL)
        break;
}
```

## Expected Test Output

This is useful to get a sense of how this will work:

```
rm -f test
cc strtok_escaped.c test.c -std=c99 -Wall -Werror -o test
./test

Test Case 0: 'apple|banana|cherry'
Token: 'apple' - ok
Token: 'banana' - ok
Token: 'cherry' - ok
PASSED

Test Case 1: 'apple\|banana|cherry'
Token: 'apple|banana' - ok
Token: 'cherry' - ok
PASSED

Test Case 2: 'apple|banana|cherry\'
Token: 'apple' - ok
Token: 'banana' - ok
Token: 'cherry\' - ok
PASSED

Test Case 3: 'apple\|banana|cherry\'
Token: 'apple|banana' - ok
Token: 'cherry\' - ok
PASSED

Test Case 4: 'apple|banana\|cherry'
Token: 'apple' - ok
Token: 'banana|cherry' - ok
PASSED

Test Case 5: 'apple\|banana\|cherry'
Token: 'apple|banana|cherry' - ok
PASSED

Test Case 6: 'apple\\|banana|cherry'
Token: 'apple\|banana' - ok
Token: 'cherry' - ok
PASSED

Test Case 7: 'apple\|banana\|cherry\'
Token: 'apple|banana|cherry\' - ok
PASSED

Test Case 8: 'apple|ba\nana|cherry'
Token: 'apple' - ok
Token: 'ba\nana' - ok
Token: 'cherry' - ok
PASSED

Test Case 9: ''
PASSED

All tests passed.
```

## license

GNUv3
