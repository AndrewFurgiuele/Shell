#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "shellFunctions.h"


//main function
int main(int argc, char** argv)  {

	if( argc == 1){
	
		char line[100];
		char cwd[256]; 
		getcwd(cwd, sizeof(cwd));
	
		do{
	
			scanf(" %[^\n]s", line);
			handleInput(line, cwd);
			puts("");
		}while(strcmp(line, "quit") != 0);	
				
	}else if( argc == 2){
		
		
		char* fileName = argv[1];
		
		FILE* fp;
		
		char* line= malloc(100);
		
		if((fp = fopen(fileName, "r")) == NULL){
			printf("Cannot open file \n");
			exit(1);
		}
		
		
		char cwd[256]; 
		getcwd(cwd, sizeof(cwd));
	
		do{
			
			memset(line, 0, 100);
			line = (char*)getLine(fp);
			handleInput(line, cwd);
			puts("");
		
		}while(strcmp( line, "quit") != 0);	
		
	}else{
		puts("wrong number of command line arguements");
		exit(1);
	}



	
	



	return 0;
}


