#include <stdio.h>
#include <shell_functions.h>
/* for use of fork, waitpid, pid etc */
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

#define TRUE 1
#define CL_MAX 10

int main(int argc, char **argv)
{
    while (TRUE){ /* repeat forever */
        type_prompt();  /*display prompt on the screen */
        
        char input_line[CL_MAX]; /*skal endres*/
        char *const parameters[50];
        int status;
        
        
        
        get_input(input_line, CL_MAX);
        
        
        //read_command(command, parameters);  read input from terminal
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
