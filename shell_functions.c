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

// add error if input_line > 1000
void get_input(char *input_line, int MAX)
{
    
    fgets(input_line, MAX, stdin);
    size_t n = sizeof(input_line) / sizeof(input_line[0]);
    
    printf("%zu\n", n);
    if (n > MAX)
    {
        printf("Size of command line input must be less than 1000 characters");
        exit(0);
    }
    printf("Glad to meet you, %s", input_line);

    
};
