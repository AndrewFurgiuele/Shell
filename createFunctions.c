#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

//function that handles creating a new file
int fFlag(char* filepath){
	
	if( fopen(filepath, "a") == NULL){
			puts("cant open file");
			printf("Error %s\n", strerror(errno));
			exit(1);
		}
		
		
	
	
	return 0;
}

//function that handles creating a new directory
int dFlag(char* dirpath){
	
	
	if(mkdir(dirpath, 0750) != 0){
			puts("failed to make Directory");
			printf("Error %s\n", strerror(errno));
		}	
	
	
	return 0;
}

//function that handles creating hard links
int hFlag(char* oldname, char* newname){
	
	if(access(oldname, F_OK) != -1 ){
			if(link(oldname, newname) != 0){
				puts("link failed");
			}
		
		}else{
			puts("this file does not exist");
		}
		
	
	
	return 0;
}

//function that handles creating soft links
int sFlag(char* oldname, char* newname){
	
	
	if(access(oldname, F_OK) != -1){
			if(symlink(oldname, newname) != 0){
				puts("link failed");
			}
		}else{
			puts("this file does not exist");
		}
		
	
	
	
	return 0;
}
