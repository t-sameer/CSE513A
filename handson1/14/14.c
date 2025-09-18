/*
============================================================================
Name : Q14.c
Author : Sameer
Description : Write a program to find the type of a file.
              a. Input should be taken from command line.
              b. program should be able to identify any type of a file.
Date: 22nd Aug, 2025.
============================================================================
*/

#include <stdio.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {

    struct stat sb;
    printf("File type of %s: ", argv[1]);
    stat(argv[1], &sb);

    switch (sb.st_mode & S_IFMT) {
        
	case S_IFREG: 
		printf("Regular file\n"); 
		break;
        
	case S_IFDIR: 
		printf("Directory\n"); 
		break;
        
	case S_IFCHR: 
		printf("Character device\n"); 
		break;
        
	case S_IFBLK: 	
		printf("Block device\n"); 
		break;
        
	case S_IFIFO: 
		printf("FIFO (named pipe)\n"); 
		break;
        
	case S_IFSOCK: 
		printf("Socket\n"); 
		break;
        
	default: 	
		printf("Unknown file type\n"); 
		break;
    }

    return 0;
}
/*
============================================================================ 
sameer@sameer-ACERPCHLY:~/Study/Systems/handsOn/14$ ./14
File type of (null): Unknown file type
sameer@sameer-ACERPCHLY:~/Study/Systems/handsOn/14$ ./14 14.c
File type of 14.c: Regular file
============================================================================
*/
