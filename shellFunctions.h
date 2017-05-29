//function splits a command into an array with each index a word
char** split(char* x);
//function that changes the working directory
int changeWorkingDirectory(char* line);

//function that prints the current directory
int printWorkingDirectory();

//function that calls the correct methods for each command
int handleInput(char* input, char* cwd);

