/*
 * Authors:  Oda Scheen Kiese and Kjetil Vaagen
 * Purpose:  to learn about shells
 *           to implement a simple shell
 *           to practice using C, fork, and exec
 * Language: C
 */

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

void get_input(char *input_line, int MAX){
    char *str;
    str = fgets(input_line, MAX, stdin);
    
    // if the line is simply a new line, return 0
    if (!(strcmp("\n", str))){
        input_line = NULL;
    }
    else {
        // Give error if input line does not end with new line - input longer than MAX
        if (input_line[strlen(input_line)-1] != '\n') {
            printf("ERROR: Size of command line input must be less than 1000 characters\n");
            exit(0);
        };
        struct Words input_words1;
        input_words1 = parser(input_line);
        execute_command(input_words1, 1);
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
    // Remove "\n" from last word
    input_words.words[input_words.size - 1] = last_char_del(input_words.words[input_words.size - 1]);
    
    return input_words;
}

char* last_char_del(char* str){
    str[strlen(str) - 1] = '\0';
    return str;
}

void execute_systemcall(struct Words input_words, bool flag) {
    // If forking is needed
    if (flag){
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
    // If no forking is needed
    } else {
        input_words.words[input_words.size] = 0;
        execvp(input_words.words[0], input_words.words);
    }
}

bool execute_pipe(struct Words words, int pipe_index){
    pid_t c1, c2;
    int fd[2];
    
    if (pipe(fd) < 0){
        printf("One of the two pipes failed.\n");
        return 0;
    }

    c1 = fork();
    if (c1 < 0){
        printf("Forked failed.\n");
        return 0;
    }

    if (c1 == 0){
        //Child 1 executing
        dup2(fd[1], STDOUT_FILENO); 
        close(fd[0]);
        close(fd[1]);
        //Run subcommand
        struct Words new_input;
        int index = 0;
        for (int i = 0; i < pipe_index; i++){
            new_input.words[index] = words.words[i];
            index++;
            new_input.size = index;
        }
        execute_command(new_input, 0);
    }
    else {

        c2 = fork();
        if (c2 < 0){
            printf("Forked failed.\n");
            return 0;
        }

        if (c2 == 0){
            //Child 2 executing
            dup2(fd[0], STDIN_FILENO); 
            close(fd[1]);
            close(fd[0]);
            //Run subcommand
            struct Words new_input;
            int index = 0;
            for (int i = pipe_index +1; i < words.size; i++){
                new_input.words[index] = words.words[i];
                index++;
                new_input.size = index;
            }
            execute_command(new_input, 0);
        }
        else{
            //Parent executing
            close(fd[0]);
            close(fd[1]);
            wait(NULL);
            wait(NULL);
            return 1;
        }
    }
}

bool execute_lcroc(struct Words words, int croc_index){
    pid_t c1, c2;
    int fd[2];
    
    if (pipe(fd) < 0){
        printf("One of the two pipes failed.\n");
        return 0;
    }
    
    c1 = fork();
    if (c1 < 0){
        printf("Forked failed.\n");
        return 0;
    }
    
    if (c1 == 0){
        //Child executing
        dup2(fd[1], STDOUT_FILENO);
        close(fd[0]);
        close(fd[1]);
        //Run subcommand
        struct Words new_input;
        int index = 0;
        for (int i = 0; i < croc_index; i++){
            new_input.words[index] = words.words[i];
            index++;
            new_input.size = index;
        }
        execute_command(new_input, 0);
        
    } else{
        //Parent executing
        wait(NULL);
        close(fd[1]);
        // Creating file for output
        FILE *f = fopen(words.words[croc_index+1], "w");
        if (f == NULL) {
            printf("Error opening file!\n");
            exit(1);
        }
        // Reading the string from the child
        char buffer[1000];
        int n;
        n = read(fd[0], buffer, 1000);
        close(fd[0]);
        fprintf(f, "%s", buffer);
        fclose(f);
        
        return 1;
    }
}

bool execute_rcroc(struct Words words, int croc_index){
    pid_t c1, c2;
    int fd[2];
    
    if (pipe(fd) < 0){
        printf("One of the two pipes failed.\n");
        return 0;
    }
    
    c1 = fork();
    if (c1 < 0){
        printf("Forked failed.\n");
        return 0;
    }
    
    if (c1 == 0){
        //Child 1 executing
        dup2(fd[1], STDOUT_FILENO);
        close(fd[0]);
        close(fd[1]);
        //Run subcommand
        struct Words new_input;
        int index = 1;
        new_input.words[0] = "cat";
        for (int i = croc_index+1; i < words.size ; i++){
            new_input.words[index] = words.words[i];
            index++;
            new_input.size = index;
        }
        execute_command(new_input, 0);
    }
    else {
        
        c2 = fork();
        if (c2 < 0){
            printf("Forked failed.\n");
            return 0;
        }
        
        if (c2 == 0){
            //Child 2 executing
            dup2(fd[0], STDIN_FILENO);
            close(fd[1]);
            close(fd[0]);
            //Run subcommand
            struct Words new_input;
            int index = 0;
            for (int i = 0; i < croc_index; i++){
                new_input.words[index] = words.words[i];
                index++;
                new_input.size = index;
            }
            execute_command(new_input, 0);
        }
        else{
            close(fd[0]);
            close(fd[1]);
            //Parent executing
            wait(NULL);
            wait(NULL);
            return 1;
        }
    }
}
              
bool execute_in_background(struct Words words, int background_index){
    pid_t c1;
    struct Words new_input;
    
    int index = 0;
    for (int i = 0; i < background_index; i++){
        new_input.words[index] = words.words[i];
        index++;
        new_input.size = index;
    }

    c1 = fork();
    if ( c1 < 0){
        printf("Fork failed\n");
    }

    if (c1 == 0){
        //Child running
        execute_command(new_input, 0);
    }
    else{
        if ((words.size - 1) > background_index){
            //Command after & needs to run in parallell
            struct Words new_input;
            int index = 0;
            for (int i = background_index + 1; i < words.size; i++){
                new_input.words[index] = words.words[i];
                index++;
                new_input.size = index;
            }
            execute_command(new_input, 1);
        }
        else{
            return 1;
        }
    }
}

void execute_command(struct Words input_words, bool flag){
    // exit if exit is typed in terminal
    if (input_words.size == 1 && !(strcmp("exit", input_words.words[0]))){
        printf("You wrote exit so the shell terminates\n");
        exit(0);
    }
    
    bool found_keyword = 0;
    for(int i = 0; i < input_words.size; i++ ) {
        if( !(strcmp("|", input_words.words[i])) ) {
            execute_pipe(input_words, i);
            found_keyword = 1;
        }
        else if( !(strcmp("<", input_words.words[i])) ) {
            execute_rcroc(input_words, i);
            found_keyword = 1;
        }
        else if( !(strcmp(">", input_words.words[i])) ) {
            execute_lcroc(input_words, i);
            found_keyword = 1;
        }
        else if( !(strcmp("&", input_words.words[i])) ) {
            found_keyword = 1;
            execute_in_background(input_words, i);
        }
    }
    
    if (!found_keyword){
        execute_systemcall(input_words, flag);
    }
    
};
