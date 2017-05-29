#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

//function splits a command into an array with each index a word
char** split(char* x){
	char* line = malloc(sizeof(char) * strlen(x)+1);
	strcpy(line, x);
	int i =0;
	char* token = strtok(x, " ");  

	while (token != NULL){
		i++;
		token = strtok(NULL," ");
	}

	
	char** array= malloc(sizeof(char) * (i+1)); 
	array[i]= NULL;
	char* token2 = strtok(line, " ");
	
	i =0;
	while (token2 != NULL){
		array[i] = token2;
		i++;
		token2 = strtok(NULL," ");
	}	
		
	return array;
}

//function that changes the working directory
int changeWorkingDirectory(char* line){
	
	//should return chwd
	char* token = strtok(line, " ");
	// should return pathname	
	token = strtok(NULL, " ");
	
	
	if(chdir(token) == 0){
		printf("Current Working Directory was changed to : %s\n", token);
	}else{
		puts("Directory did not change");
		printf("Error %s\n", strerror(errno));
	}
	return 0;
}

//function that prints the current directory
int printWorkingDirectory(){
	char cw[1024];
	
	if(getcwd(cw, sizeof(cw))!= NULL){
		printf("The current Working Directory: %s\n", cw);
	}else{
		puts("cannot get the current working directory");
		exit(1);
	}
		
	return 0;
}

//function that calls the correct methods for each command
int handleInput(char* input, char* cwd){

	char* list ="/list";
	char* create ="/create";
	

	char fullAddressList[1000];
	char fullAddressCreate[1000];
	
	strcpy(fullAddressList, cwd);
	strcat(fullAddressList, list);

	strcpy(fullAddressCreate, cwd);
	strcat(fullAddressCreate, create);
	
	
	
	char* line = malloc(sizeof(char) * strlen(input) +1);
	strcpy(line, input);
	
	char* token = strtok(input, " ");

	
	if(strcmp(token, "wd") == 0){
		printWorkingDirectory();
	}else if(strcmp(token, "chwd") == 0){
		changeWorkingDirectory(line);
	}else if(strcmp(token, "create") == 0){
	
		pid_t child;
		child = fork();
		
		if(child ==0){
			//child
	
			execvp(fullAddressCreate, split(line));
			
			exit(0);
		}else{
			if (child == (pid_t)(-1)) {
				puts("Fork failed");
				exit(1);
			}else{
				int childRetStat;
				//parent
				waitpid(child, &childRetStat, 0);
				if(childRetStat !=0){
					puts("child did not terminate correctly");
				}
			}
		}
		
		
		
	}else if(strcmp(token, "list") == 0){
		
		pid_t child;
		child = fork();
		
		if(child ==0){
			//child

			execvp(fullAddressList, split(line));
			
			
			
			exit(0);
		}else{
			if (child == (pid_t)(-1)) {
				puts("Fork failed");
				exit(1);
			}else{
				int childRetStat;
				//parent
				waitpid(child, &childRetStat, 0);
				if(childRetStat !=0){
					puts("child did not terminate correctly");
				}
			}
		}
		
		
	}else if(strcmp(token, "quit") == 0){
		puts("goodbye");
	}else{
		puts("not a valid command");
		return 1;
	}
	
	
	
	
	
	
	return 0;
}

