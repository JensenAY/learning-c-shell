#include "s_read.h"
#include <string.h>


int s_read(char *input, char **args)
{
    int i = 0;

    char *token = strtok(input, TOKEN_SEPS);

    while (token != NULL && i < MAX_ARGS - 1)
    {
        args[i++] = token;
        token = strtok(NULL, TOKEN_SEPS);
    };

    args[i] = NULL;
    return i;
};
