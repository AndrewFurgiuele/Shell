//gets size of a file
int getSize(char* name);

//gets the permissions of a file
int getPermisions(char* name);

//gets inode of a file
int getInode(char* name);


//function that lists all the non hidden files in directory
int listFiles(char* filepath);
	

//function that lists all the hidden files in directory
int listHiddenFiles(char* filepath);

//function that lists all the non hidden files in directory and their stats
int listFilesStats(char* filepath);
