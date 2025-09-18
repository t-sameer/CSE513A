/*
============================================================================
Name : 10.c
Author : Sameer
Description : 10. Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10 bytes (use lseek) and write again 10 bytes.
a. check the return value of lseek
b. open the file with od and check the empty spaces in between the data.
Date: 26th Aug, 2025.
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
	
	int fd = open("file1.bin", O_CREAT | O_RDWR | O_TRUNC, 0644);

	const char *buffer1 = "AAAAAAAAA\n";

	int firstwrite = write(fd, buffer1, sizeof(buffer1));
	
	if(firstwrite < sizeof(buffer1)){
		perror("first write error : ");
		return -1;
	}

	lseek(fd, 10, SEEK_CUR);

	const char *buffer2 = "BBBBBBBBB\n";

	int secondwrite = write(fd, buffer2, sizeof(buffer2));

	if(secondwrite < sizeof(buffer2)){
		perror("second write error");
		return -1;
	}
	close(fd);
	printf("successfull");
	return 0;
}

/*
============================================================================
Output:
sameer@sameer-ACERPCHLY:~/Study/Systems/handsOn$ gcc 10.c -o lseek
sameer@sameer-ACERPCHLY:~/Study/Systems/handsOn$ ./lseek
successfullsameer@sameer-ACERPCHLY:~/Study/Systems/handsOn$ od -c file1.txt
0000000   A   A   A   A   A   A   A   A  \0  \0  \0  \0  \0  \0  \0  \0
0000020  \0  \0   B   B   B   B   B   B   B   B
0000032
============================================================================
*/
