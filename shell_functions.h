struct Words {
    char* words[50];
    int size;
};

// Display prompt on screen
void type_prompt();

// Puts command line input in input_line
void get_input(char *input_line, int MAX);

// Unfinished - executes the commands given from the terminal
void execute_command(struct Words words);

