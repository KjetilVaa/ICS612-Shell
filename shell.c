#include <stdio.h>
#include <shell_functions.h>
/* for use of fork, waitpid, pid etc */
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

#define TRUE 1
#define CL_MAX 1000

int main(int argc, char **argv)
{
    while (TRUE){ /* repeat forever */
        char input_line[CL_MAX];
        
        type_prompt();  /*display prompt on the screen */
        get_input(input_line, CL_MAX);
        parser(input_line);
        
    }
    return 0;
};
