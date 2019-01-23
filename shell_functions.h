struct Words {
    char* words[1000];
    int size;
};

void type_prompt(); /* display prompt on the screen*/


// Puts command line input in input_line
void get_input(char *input_line, int MAX);

// Parsing command line input into words
struct Words parser(char *input_line);