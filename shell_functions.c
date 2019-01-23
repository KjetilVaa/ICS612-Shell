#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <shell_functions.h>
#include <unistd.h>

void type_prompt(){
    printf("$ ");
};

void get_input(char *input_line, int MAX){
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

void execute_command(struct Words input_words){
    // exit if exit is typed in terminal
    if (input_words.size == 1 && !(strcmp("exit", input_words.words[0]))){
        exit(0);
    }
    
    for(int i; i < input_words.size; i++ ) {
        printf("%s\n", input_words.words[i]);
        if( !(strcmp(">", input_words.words[i])) ) {
            //do
        }
        else if( !(strcmp("<", input_words.words[i])) ) {
            //do
        }
        else if( !(strcmp("|", input_words.words[i])) ) {
            //do
        }
        else if( !(strcmp("&", input_words.words[i])) ) {
            //do
        }
    };

};


