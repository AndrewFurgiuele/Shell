//function that handles creating a new file
int fFlag(char* filepath);
	
//function that handles creating a new directory
int dFlag(char* dirpath);
	
//function that handles creating hard links
int hFlag(char* oldname, char* newname);
	
//function that handles creating soft links
int sFlag(char* oldname, char* newname);