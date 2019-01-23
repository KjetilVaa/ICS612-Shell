#include <stdio.h>
#include <shell_functions.h>
/* for use of fork, waitpid, pid etc */
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

#define TRUE 1

int main()
{
    while (TRUE){ /* repeat forever */
        type_prompt();  /*display prompt on the screen */
        
        char *command; /*skal endres*/
        char *const parameters[50];
        int status;
        
        
        
        get_input(command);
        
        
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
