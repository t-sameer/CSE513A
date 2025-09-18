/*
============================================================================
Name : 4.c
Author : Sameer
Description : Write a program to open an existing file with read write mode. Try O_EXCL flag also
Date: 28th Aug, 2025.
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
	int fd;

	fd = open("file.txt", O_CREAT, O_EXCL, O_RDWR);

	if(fd == -1){
		perror("file opening failed");
		return 1;
	}

	else{
		printf("file opened successfully with fd : %d", fd);
	}
	close(fd);
	return 0;
}
/*
============================================================================
Output : 
sameer@sameer-ACERPCHLY:~/Study/Systems/handsOn$ gcc 4.c -o excl
sameer@sameer-ACERPCHLY:~/Study/Systems/handsOn$ ./excl
file opened successfully with fd : 3
============================================================================
*/
