#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//function returns a line from the script of commands
char* getLine(FILE* stream){
	char* line= malloc(sizeof(char) * 100);
	char temp[100];
	
	fgets(temp, sizeof(temp), stream);
			

	strcpy(line, temp);
	
	strtok(line, "\n");	
	
	return line;	
}
