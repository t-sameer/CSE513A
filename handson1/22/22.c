/*
============================================================================
Name : Q22.c
Author : Sameer
Description :Write a program, open a file, call fork, and then write to the file by both the child as well as the parent processes. Check output of the file.
Date: 20th Aug, 2025.
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc, char *argv[]) 
	{
	int fd;

	fd = open(argv[1], O_WRONLY | O_APPEND | O_CREAT, 0644);
	char buf[100];

	if(fork()){
		sprintf(buf, "Written by child with pid:  %d\n", getpid());
		write(fd, &buf, sizeof(buf));
	}
	else{
		sprintf(buf, "Written by parent with : %d\n", getpid());
		write(fd, &buf, sizeof(buf));
	}
	close(fd);
	return 0;
}
/*
============================================================================
sameer@sameer-ACERPCHLY:~/Study/Systems/handsOn/22$ gcc 22.c -o 22
sameer@sameer-ACERPCHLY:~/Study/Systems/handsOn/22$ ./22 file.txt
sameer@sameer-ACERPCHLY:~/Study/Systems/handsOn/22$ cat file.txt
Written by child with pid:  9502
Written by parent with : 9503
============================================================================
*/


