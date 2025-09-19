/*
============================================================================
Name : 6.c
Author : Sameer
Description : Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls
Date: 25th Aug, 2025.
============================================================================
*/

#include <unistd.h>
#include <stdlib.h>

int main(){
	char buffer[100];
	read(0, buffer, 100);
	write(1, buffer, 100);
	return 0;
}

/*
============================================================================
sameer@sameer-ACERPCHLY:~/Study/Systems/handsOn$ gcc 6.c -o readwrite
sameer@sameer-ACERPCHLY:~/Study/Systems/handsOn$ ./readwrite
reading and writing using read and write system call
reading and writing using read and write system call
�J�u�wp{sameer@sameer-ACERPCHLY:~/Study/Systems/handsOn$
============================================================================
*/
