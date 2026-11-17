#include <stdio.h>
#include <stdlib.h>     // exit()
#include <unistd.h>     // fork(), execvp()
#include <sys/types.h>  // pid_t
#include <sys/wait.h>   // waitpid()
#include "s_execute.h"

int s_execute(char *cmd, char **cmd_args)
{
    fprintf(stdout, "Executing `%s`!\n", cmd);

    int status;

    pid_t pid;
    pid = fork();

    if (pid < 0)
    {
        fprintf(stderr, "Could not execute\n");
        return -1;
    }

    if (pid == 0)
    {
        execvp(cmd, cmd_args);
    }
    else
    {
        if (waitpid(pid, &status, 0) != pid)
        {
            fprintf(stderr, "Could not wait for kiddo!\n");
            return -1;
        }
    };
    return status;
};
