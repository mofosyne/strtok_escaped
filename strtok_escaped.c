#include <string.h>

char *strtok_escaped_r(char **last_token_end, char *str, const char *delim)
{
    // Tokenise a string from a single char deliminator (Reentrant)
    // (strtok can deal with a deliminator string but for my purpose of splitting a psv table I only need one char)
    // (There are better ways to optimise this, but just wanted something to work for now)
    // https://gist.github.com/mofosyne/81c94740c0f33259606afa823562914c

    char *token_start = (*last_token_end == NULL) ? str : *last_token_end + 1;
    char *token_end = token_start;

    while (*token_end != '\0')
    {
        if (*token_end == '\\' && *(token_end + 1) == delim[0])
        {
            // Handle escaped deliminator
            memmove(token_end, token_end + 1, strlen(token_end + 1) + 1);
            token_end++;
        }
        else if (strchr(delim, *token_end) != NULL)
        {
            // Found delimiter
            *token_end = '\0';
            *last_token_end = token_end;
            return token_start;
        }
        token_end++;
    }

    if (*token_start == '\0')
    {
        return NULL;
    }

    *last_token_end = token_end - 1;
    return token_start;
}

char *strtok_escaped(char *str, const char *delim)
{
    // Tokenise a string from a single char deliminator (Classic Non-Reentrant Strtok Style)
    // (strtok can deal with a deliminator string but for my purpose of splitting a psv table I only need one char)
    // (There are better ways to optimise this, but just wanted something to work for now)
    // https://gist.github.com/mofosyne/81c94740c0f33259606afa823562914c
    static char *last_token_end = NULL;

    if (str == NULL && last_token_end == NULL)
    {
        return NULL;
    }

    char *token_start = (str != NULL) ? str : last_token_end + 1;
    char *token_end = token_start;

    while (*token_end != '\0')
    {
        if (*token_end == '\\' && *(token_end + 1) == delim[0])
        {
            // Handle escaped deliminator
            memmove(token_end, token_end + 1, strlen(token_end + 1) + 1);
            token_end++;
        }
        else if (strchr(delim, *token_end) != NULL)
        {
            // Found delimiter
            *token_end = '\0';
            last_token_end = token_end;
            return token_start;
        }
        token_end++;
    }

    if (*token_start == '\0')
    {
        return NULL;
    }

    last_token_end = token_end - 1;
    return token_start;
}
