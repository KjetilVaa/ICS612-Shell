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

// Unfinished - Handles commands given from the terminal.
// Flag indicated whether forking has to be done or not
void execute_command(struct Words words, bool flag);

// Handles pipes
bool execute_pipe(struct Words words, int pipe_index);
