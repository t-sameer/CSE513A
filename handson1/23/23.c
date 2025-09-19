/*
============================================================================
Name : Q23.c
Author : Sameer
Description :Write a program to create Zombie state of a running program.
Date: 20th Aug, 2025.
============================================================================
*/


#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

int main() {
	if (!fork()) {
		printf("Child PPID: %d\n", getppid());
	}
	else {
		printf("This is parent process %d\n", getpid());
		sleep(10);
		wait(0);
	}
}

/*
============================================================================
sameer@sameer-ACERPCHLY:~/Study/Systems/handsOn/23$ gcc 23.c -o 23
sameer@sameer-ACERPCHLY:~/Study/Systems/handsOn/23$ ./23
This is parent process 5297
Child PPID: 5297
============================================================================
*/

