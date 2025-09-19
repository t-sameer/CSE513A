/*
============================================================================
Name : 8.c
Author : Sameer
Description : Write a program to open a file in read only mode, read line by line and display each line as it is read. Close the file when end of file is reached.
Date: 25th Aug, 2025.
============================================================================
*/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(){
	int fd =  open("file1.txt", O_RDONLY);
	
	if(fd == -1){
		perror("error opening file");
		return -1;
	}
	char buffer[1000];
	ssize_t bytesread;
	char line[1000];
	int linidx = 0;

	while((bytesread = read(fd, buffer, sizeof(buffer))) > 0){
		for(int i = 0; i < bytesread; i++){
			line[linidx++] = buffer[i];

			if(buffer[i] == '\n'){
				line[linidx] = '\0';
				printf("%s", line);
				linidx = 0;
			}
		}
	}

	if(bytesread < 0){
		perror("Error reading file");
	}

	close(fd);
	return 0;
}
/*
============================================================================
Output:
sameer@sameer-ACERPCHLY:~/Study/Systems/handsOn$ gcc 8.c -o readline
sameer@sameer-ACERPCHLY:~/Study/Systems/handsOn$ ./readline
This is line 1
This is line 2 
This is line 3
============================================================================
*/

