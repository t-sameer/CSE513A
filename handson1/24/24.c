/*
============================================================================
Name : Q24.c
Author : Sameer
Description :Write a program to create an orphan process.
Date: 20th Aug, 2025.
============================================================================
*/


#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main() {
	if (!fork()) {
		printf("Child PPID: %d\n", getppid());
		sleep(2);
		printf("Orphan PPID: %d\n", getppid());
	}
	else {
		printf("This is parent process %d\n", getpid());
		exit(0);
	}
}

/*
============================================================================
sameer@sameer-ACERPCHLY:~/Study/Systems/handsOn/24$ gcc 24.c -o 24
sameer@sameer-ACERPCHLY:~/Study/Systems/handsOn/24$ ./24
This is parent process 4742
Child PPID: 4742
sameer@sameer-ACERPCHLY:~/Study/Systems/handsOn/24$ Orphan PPID: 1929
============================================================================
*/

