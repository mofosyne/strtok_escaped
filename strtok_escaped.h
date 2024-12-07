#ifndef __STRTOK_ESCAPED_H
#define __STRTOK_ESCAPED_H
#ifdef __cplusplus
extern "C"
{
#endif

// Reentrant
char *strtok_escaped_r(char **last_token_end, char *str, const char *delim);

// Non Reentrant
char *strtok_escaped(char *str, const char *delim);
#ifdef __cplusplus
}
#endif
#endif
