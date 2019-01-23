#include <stdio.h>
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

void get_input(char *input_line)
{
    fgets(input_line, 1000, stdin);
    printf("Glad to meet you, %s.n", input_line);
    
};
