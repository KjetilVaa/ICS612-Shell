/*
 * Authors:  Oda Scheen Kiese and Kjetil Vaagen
 * Purpose:  to learn about shells
 *           to implement a simple shell
 *           to practice using C, fork, and exec
 * Language: C
 */

typedef int bool;

#define TRUE 1
#define FALSE 0

struct Words {
    char* words[50];
    int size;
};

// Display prompt on screen
void type_prompt();

// Puts command line input in input_line
void get_input(char *input_line, int MAX);

// Parsing command line input into words
struct Words parser(char *input_line);

// Deletes last char in a string
char* last_char_del(char* str);

// Handles pipes
bool execute_pipe(struct Words words, int pipe_index);

// Handles left crocodile sign
bool execute_lcroc(struct Words words, int croc_index);

// Handles right croc sign
bool execute_rcroc(struct Words words, int croc_index);

// Fork process and execute in background
bool execute_in_background(struct Words words, int background_index);

// Handles commands given from the terminal.
// Flag indicated whether forking has to be done or not
void execute_command(struct Words words, bool flag);
