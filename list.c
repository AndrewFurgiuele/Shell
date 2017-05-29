#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>

#include "listFunctions.h"

//main function
int main(int argc, char** argv)  {
	
	if(argc ==1){
		//list 
		
		listFiles(".");
	
		
	}else{
			
		char* flag = argv[1];
		
		
		if(strcmp(flag, "-i") == 0){
			if(argc == 3){
				//list -i pathname
				
				char* filepath = argv[2];
				listFilesStats(filepath);
				
				
			}else if(argc == 2){
				//list -i
				listFilesStats(".");
				
			}else{
				puts("incorrect number of arguements");
				return 0;
			}
			
		
			
			
			
			
		}else if(strcmp(flag, "-h") == 0){
			if(argc == 3){
				//list -h pathname
				char* filepath = argv[2];
				listHiddenFiles(filepath);
				
			}else if(argc == 2){
				//list -h
				listHiddenFiles(".");
			}else{
				puts("incorrect number of arguements");
				return 0;
			}
			
			
		}else{
			if(argc != 2){
			puts("incorrect number of arguements");
			return 0;
			}else{
				//list pathname
				char* filepath = argv[1];
				listFiles(filepath);
				
			}
			
		}
	}

	return 0;
}
