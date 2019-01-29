#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <shell_functions.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void type_prompt(){
    printf("$ ");
};

void execute_systemcall(struct Words input_words) {
    pid_t pid = fork();
    
    if (pid == -1){
        printf("Forking child failed\n");
        return;
    } else if (pid == 0) {
        input_words.words[input_words.size] = 0;
        if (execvp(input_words.words[0], input_words.words) > 0) {
            printf("System call failed\n");
        }
        exit(0);
    } else {
        wait(NULL);
    }
}

void get_input(char *input_line, int MAX){
    char *str;
    str = fgets(input_line, MAX, stdin);
    
    // if the line is simply a new line, return 0
    if (!(strcmp("\n", str))){
        input_line = NULL;
        printf("entred 0\n");
    }
    else {
        // Give error if input line does not end with new line - input longer than MAX
        if (input_line[strlen(input_line)-1] != '\n') {
            printf("ERROR: Size of command line input must be less than 1000 characters\n");
            exit(0);
        };
        struct Words input_words1;
        input_words1 = parser(input_line);
        execute_command(input_words1);
    };
};

void execute_command(struct Words input_words){
    // exit if exit is typed in terminal
    if (input_words.size == 1 && !(strcmp("exit\n", input_words.words[0]))){
        printf("You wrote exit so the shell terminates\n");
        exit(0);
    }
    
    bool found_keyword = 0;

    for(int i; i < input_words.size; i++ ) {
        if( !(strcmp("|", input_words.words[i])) ) {
            //Run pipe function with the two commands
            execute_pipe(input_words, i);
            found_keyword = 1;
        }
        else if( !(strcmp("<", input_words.words[i])) ) {
            found_keyword = 1;
            //do
        }
        else if( !(strcmp(">", input_words.words[i])) ) {
            found_keyword = 1;
            //do
        }
        else if( !(strcmp("&", input_words.words[i])) ) {
            found_keyword = 1;
            //do
        }
    }

    if (!found_keyword){
        printf("This is a regular system call \n");
        execute_systemcall(input_words);
    }
    
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
    
    input_words.words[input_words.size - 1] = last_char_del(input_words.words[input_words.size - 1]);
    
    return input_words;
}

char* last_char_del(char* str)
{
    str[strlen(str) - 1] = '\0';
    return str;
}

bool execute_pipe(struct Words words, int pipe_index){
    // fd[0] --> read-end, fd[1] --> write-end
    int fd[2];
    pid_t c1, c2;
    int status;
    
    if (pipe(fd) == -1){
        printf("One of the two pipes failed.\n");
        return 0;
    }
    fflush(stdout);
    c1 = fork();
    if (c1 < 0){
        printf("Forked failed.\n");
        return 0;
    }

    if (c1 == 0){
        //Child executing
        printf("Child executing! \n");
        for (int i = 0; i++; i < pipe_index){
            printf("%s\n", words.words[i]);
        }
        exit(0);
    }
    else {
        //Parent executing... Wait for both children to execute
        sleep(10);
        printf("running parent \n");
    }
    return 1;
}
