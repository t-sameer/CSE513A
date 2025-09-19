/*
============================================================================
Name : 1A.c
Author : Sameer
Description : 1. Create the following types of a files using (i) shell command (ii) system call
a. soft link (symlink system call)
b. hard link (link system call)
c. FIFO (mkfifo Library Function or mknod system call)
Date: 28th Aug, 2025.
============================================================================
*/

#include<stdio.h>

#include<unistd.h>

int main(void){
	const char *target = "file1";
	const char *name = "linktofile1";
	
	int flag = symlink(target, name);
	
	if(flag == 0){
		printf("link created successfully");
		}

	else{
		printf("link creation failed");
		}
  
	return 0;
}

/*
============================================================================
Output:
sameer@sameer-ACERPCHLY:~/Study/Systems/handsOn/1$ gcc 1A.c -o 1A
sameer@sameer-ACERPCHLY:~/Study/Systems/handsOn/1$ ./1A
link created successfullysameer@sameer-ACERPCHLY:~/Study/Systems/handsOn/1$ ls
1A  1A.c  1B.c  1C  1C.c  file1  linktofile1  myfifo
============================================================================
*/

