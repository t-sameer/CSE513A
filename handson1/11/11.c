/*
============================================================================
Name : Q11.c
Author : Sameer
Description : Write a program to open a file, duplicate the file descriptor and append the file with both the
              descriptors and check whether the file is updated properly or not.
              a. use dup
              b. use dup2
              c. use fcntl
Date: 28th Aug, 2025.
============================================================================
*/
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>

int main(){
        int fd1 = open("file.txt", O_WRONLY);
	
	int fd2 = dup(fd1);

	char buf1[] = "modified using dup()\n";
	write(fd2 ,&buf1 ,sizeof(buf1));
        
	int fd3 = dup2(fd1, 10);
        
	char buf2[] = "modified using dup2()\n";
	write(fd3 ,&buf2 ,sizeof(buf2));
        
	int fd4 = fcntl(fd1, F_DUPFD, 0);
        
	char buf3[] = "modified using fcntl()\n";
	write(fd4, &buf3, sizeof(buf3));
	
	return 0;
}

/*
============================================================================
Output:
sameer@sameer-ACERPCHLY:~/Study/Systems/handsOn/11$ gcc 11.c -o 11
sameer@sameer-ACERPCHLY:~/Study/Systems/handsOn/11$ ./11
sameer@sameer-ACERPCHLY:~/Study/Systems/handsOn/11$ cat file.txt
modified using dup()
modified using dup2()
modified using fcntl()
============================================================================
*/
