#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

#include "createFunctions.h"

int main(int argc, char** argv){


	char* flag = argv[1];
	
	
	if(strcmp(flag, "-f") == 0){
		if(argc != 3){
			puts("incorrect number of arguements");
			return 0;
		}
		
		char* filepath = argv[2];
		
		fFlag(filepath);
	


		
	}else if(strcmp(flag, "-d") == 0){
		if(argc != 3){
			puts("incorrect number of arguements");
			return 0;
		}
		
		
		char* dirpath = argv[2];
		
		dFlag(dirpath);
		
	}else if(strcmp(flag, "-h") == 0){
		if(argc != 4){
			puts("incorrect number of arguements");
			return 0;
		}
		
		char* oldname = argv[2];
		char* newname = argv[3];
		
		
		hFlag(oldname, newname);
		
		
		
		
	}else if(strcmp(flag, "-s") == 0){
		if(argc != 4){
			puts("incorrect number of arguements");
			return 0;
		}
		
		char* oldname = argv[2];
		char* newname = argv[3];
		
		sFlag(oldname, newname);
		
	}else{
		puts("incorrect command format");
		
	}


	return 0;
}
