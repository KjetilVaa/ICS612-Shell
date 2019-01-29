#include <stdio.h>
#include <shell_functions.h>
/* for use of fork, waitpid, pid etc */
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

typedef int bool;
#define TRUE 1
#define FALSE 0
#define CL_MAX 20

int main(int argc, char **argv)
{
    while (TRUE){ /* repeat forever */
        char input_line[CL_MAX];
        
        type_prompt();  /*display prompt on the screen */
        get_input(input_line, CL_MAX);
        
        struct Words test = {
            {"exit"},
            1
        };        
    }
    return 0;
};
