/*
============================================================================
Name : Q21.c
Author : Sameer
Description :Write a program, call fork and print the parent and child process id.
Date: 20th Aug, 2025.
============================================================================
*/

#include<stdio.h>
#include<unistd.h>

int main() {
	if(!fork()){
		printf("Child process pid: %d\n", getpid());
	}
	else{
		printf("Parent process pid: %d\n", getpid());
	}
	return 0;
}
/*
============================================================================
sameer@sameer-ACERPCHLY:~/Study/Systems/handsOn/21$ gcc 21.c -o 21
sameer@sameer-ACERPCHLY:~/Study/Systems/handsOn/21$ ./21
Child process pid: 9260
Parent process pid: 9261
============================================================================
*/

