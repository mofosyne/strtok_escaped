#include <stdio.h>
#include <string.h>

#include "strtok_escaped.h"

int main() {
    // Define test cases
    typedef struct {
        char *input;
        char *expected_tokens[10]; // Maximum of 10 tokens per test case
    } Test;

    char *delim = "|";
    Test tests[] = {
        {"apple|banana|cherry", {"apple", "banana", "cherry", NULL}},
        {"apple\\|banana|cherry", {"apple|banana", "cherry", NULL}},
        {"apple|banana|cherry\\", {"apple", "banana", "cherry\\", NULL}},
        {"apple\\|banana|cherry\\", {"apple|banana", "cherry\\", NULL}},
        {"apple|banana\\|cherry", {"apple", "banana|cherry", NULL}},
        {"apple\\|banana\\|cherry", {"apple|banana|cherry", NULL}},
        {"apple\\\\|banana|cherry", {"apple\\|banana", "cherry", NULL}},
        {"apple\\|banana\\|cherry\\", {"apple|banana|cherry\\", NULL}},
        {"apple|ba\\nana|cherry", {"apple", "ba\\nana", "cherry", NULL}},
        {"", {NULL}} // Empty string test case
    };

    int num_tests = sizeof(tests) / sizeof(tests[0]);
    int failed_tests = 0;

    // Iterate through each test case
    for (int i = 0; i < num_tests; i++) {
        printf("\nTest Case %d: '%s'\n", i, tests[i].input);
        int failed_sub_tests = 0;

        // Copy input string to a buffer for tokenization
        char str[512];
        strcpy(str, tests[i].input);

        // Tokenize the string and compare tokens with expected tokens
        int token_index = 0;
        char *token = strtok_escaped(str, delim);
        while (token != NULL && tests[i].expected_tokens[token_index] != NULL) {

            if (strcmp(token, tests[i].expected_tokens[token_index]) != 0) {
                printf("Token Mismatch - got '%s' but expecting '%s' - failed\n", token, tests[i].expected_tokens[token_index]);
                failed_sub_tests++;
            } else {
                printf("Token: '%s' - ok\n", token);
            }

            token_index++;
            token = strtok_escaped(NULL, delim);
        }

        if (tests[i].expected_tokens[token_index] != NULL) {
            printf("Incorrect number of tokens\n");
            failed_sub_tests++;
        }

        if (failed_sub_tests) {
            failed_tests++;
            printf("FAILED\n");

        }else {
            printf("PASSED\n");
        }
    }

    if (failed_tests > 0) {
        printf("\n%d test(s) failed.\n", failed_tests);
        return 1;
    } else {
        printf("\nAll tests passed.\n");
        return 0;
    }
}