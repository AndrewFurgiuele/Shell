#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>

//gets size of a file
int getSize(char* name){
	int ret =0;
	struct stat x;	
	stat(name, &x);
	ret = x.st_size;		
	return ret;
}

//gets the permissions of a file
int getPermisions(char* name){
	int ret =0;	
	struct stat x;	
	stat(name, &x);
	ret = x.st_mode;
	ret -=32768;
	return ret;
}


//gets inode of a file
int getInode(char* name){
	int ret =0;
	struct stat x;	
	stat(name, &x);
	ret = x.st_ino;	
	return ret;
}

//function that lists all the non hidden files in directory
int listFiles(char* filepath){
	
	DIR *d;
	struct dirent *direct;
	
	if((d = opendir(filepath)) == NULL){
		puts("could not open directory");
		printf("Error %s\n", strerror(errno));
		return 1;
	}
	
	while((direct = readdir(d))!= NULL){
	
	char* name = direct -> d_name;
		if(name[0] != '.'){
			printf("%s\n", name);
		}
	
	}
	
	closedir(d);

	
	
	
	
	return 1;
}

//function that lists all the hidden files in directory
int listHiddenFiles(char* filepath){
	
	DIR *d;
	struct dirent *direct;
	
	if((d = opendir(filepath)) == NULL){
		puts("could not open directory");
		printf("Error %s\n", strerror(errno));
		return 1;
	}
	
	while((direct = readdir(d))!= NULL){
	
	char* name = direct -> d_name;
		if(name[0] == '.'){
			printf("%s\n", name);
		}
	
	}
	
	closedir(d);

	
	
	
	
	return 1;
}

//function that lists all the non hidden files in directory and their stats
int listFilesStats(char* filepath){
	
	DIR *d;
	struct dirent *direct;
	
	if((d = opendir(filepath)) == NULL){
		puts("could not open directory");
		printf("Error %s\n", strerror(errno));
		return 1;
	}
	
	while((direct = readdir(d))!= NULL){
	
	char* name = direct -> d_name;
	int size =getSize(name);
	int perm =getPermisions(name);
	int inode =getInode(name);
	
	
	struct stat s;
	stat(name, &s);
	
	if(s.st_mode & S_IFREG){
		if(name[0] != '.'){
			printf("%s Size(bytes): %d Permissions(octal): %o inode: %d\n", name, size, perm, inode);
		}
		}
	}
	
	closedir(d);

	
	
	
	
	return 1;
}
