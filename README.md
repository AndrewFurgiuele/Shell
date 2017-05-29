# Shell
A shell program written in C.
compiled with gcc 

commands:
  shell402
      starts a shell that acepts commands
      
  shell402 file
      runs a list of commands specified in the file
 
 list
      prints information about all files in thedirectory
      
  list pathname
      lists files specified in the pathname
      
  list -i
      lists extra information about files in current directory
      
  list -i pathname
      lists extra information about the files in the pathname
      
  list -h
      lists hidden files in current directory
      
  list -h pathname
      lists hidden files in pathname
      
  create -f filepath
      creates an empty file in specified path
      
  create -d dirpath
      creates an empty directory in specified path
      
  create -h oldname linkname
      creates a hardlink between a file (oldname) and a link (linkname)
      
  create -s oldname linkname
      creates a symbolic link between a file and a link
      
  
  wd
      prints the current orking directory
      
  chwd pathname
      changes the current working directory to the pathname
      
  quit
      exits the shell
      



