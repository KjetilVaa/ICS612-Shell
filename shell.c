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
        
         
        /*
        if (fork() != 0){ // fork off child process
            // Parent code
            waitpid(1, &status, 0); // wait for child to exit
        } else {
            // Child code
            execve(command, parameters, 0); //execute command
        }*/
        
    }
    return 0;
};
