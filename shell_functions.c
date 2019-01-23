#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <shell_functions.h>
#include <unistd.h>

void type_prompt(){
    printf("$ ");
};

bool get_input(char *input_line, int MAX){
    char *str;
    str = fgets(input_line, MAX, stdin);
    
    // if the line is simply a new line, return 0
    if (!(strcmp("\n", str))){
        input_line = NULL;
        printf("entred 0\n");
        return 0;
    }
    else {
        // Give error if input line does not end with new line - input longer than MAX
        if (input_line[strlen(input_line)-1] != '\n') {
            printf("ERROR: Size of command line input must be less than 1000 characters\n");
            exit(0);
        };
        return 1;
    };
};

void execute_command(struct Words input_words){
    // exit if exit is typed in terminal
    if (input_words.size == 1 && !(strcmp("exit\n", input_words.words[0]))){
        printf("You wrote exit so the shell terminates\n");
        exit(0);
    }
    
    for(int i; i < input_words.size; i++ ) {
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

struct Words parser(char* input_line){
    struct Words input_words;
    int index = 0;
    char* token = strtok(input_line, " ");
    while(token != NULL){
        input_words.words[index] = token;
        index++;
        input_words.size = index;
        token = strtok(NULL, " ");
    }
    
    printf("Number of words: %d\n", input_words.size);
    printf("The word(s) are: \n");
    for(int i = 0; i < input_words.size; i++ ) {
        printf("%s\n", input_words.words[i]);
    };
           
    return input_words;
}
