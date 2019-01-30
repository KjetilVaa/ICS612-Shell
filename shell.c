/*
 * Authors:  Oda Scheen Kiese and Kjetil Vaagen
 * Purpose:  to learn about shells
 *           to implement a simple shell
 *           to practice using C, fork, and exec
 * Language: C
 */

#include <stdio.h>
#include <shell_functions.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

typedef int bool;
#define TRUE 1
#define FALSE 0
#define CL_MAX 1000

int main(int argc, char **argv)
{
    while (TRUE){ /* repeat forever */
        char input_line[CL_MAX];
        
        type_prompt();  /*display prompt on the screen */
        get_input(input_line, CL_MAX);
    }
    return 0;
};
