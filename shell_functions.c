#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <shell_functions.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>

void type_prompt(){
    printf("$ ");
};

void read_command(const char *command, char *const parameters[]) {
    printf("hei");
};

void get_input(char *input_line, int MAX)
{
    char *str;
    str = fgets(input_line, MAX, stdin);
    
    if (str != NULL){
        // Give error input line does not end with new line
        if (input_line[strlen(input_line)-1] != '\n') {
            printf("ERROR: Size of command line input must be less than 1000 characters\n");
            exit(0);
        }
    };
};
