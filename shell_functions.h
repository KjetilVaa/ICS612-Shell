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
bool get_input(char *input_line, int MAX);

// Unfinished - executes the commands given from the terminal
void execute_command(struct Words words);

// Parsing command line input into words
struct Words parser(char *input_line);
