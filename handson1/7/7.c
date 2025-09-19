/*
============================================================================
Name : 7.c
Author : Sameer
Description : 7. Write a program to copy file1 into file2 ($cp file1 file2).
Date: 25th Aug, 2025.
============================================================================
*/
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(){
	
	char buffer[1000]; //RW work with raw byte char*
	int fd1 = open("file1.txt", O_RDONLY);
	int fd2 = open("file2.txt", O_CREAT | O_WRONLY, 0644);
	int bytesread;

	if(fd1 == -1 || fd2 == -1){
	       	perror("cannot open files");
		return -1;
	}

	while((bytesread = read(fd1, buffer, sizeof(buffer))) > 0){
			write(fd2, buffer, bytesread);
			}

	printf("file copied successfully");
	close(fd1);
	close(fd2);
	return 0;
	}
/*
============================================================================
Output: 
sameer@sameer-ACERPCHLY:~/Study/Systems/handsOn$ gcc 7.c -o copyfile
sameer@sameer-ACERPCHLY:~/Study/Systems/handsOn$ ./copyfile
file copied successfullysameer@sameer-ACERPCHLY:~/Study/Systems/handsOn$ cat file1.txt
file1.txt 
this is file1
sameer@sameer-ACERPCHLY:~/Study/Systems/handsOn$ cat file2.txt
file1.txt 
this is file1
============================================================================
*/


