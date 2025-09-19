/*
============================================================================
Name : 5.c
Author : Sameer
Description : Write a program to create five new files with infinite loop. Execute the program in the background
and check the file descriptor table at /proc/pid/fd.
Date: 24th Aug, 2025.
============================================================================
*/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(){
	
	int fd[5];
	const char *files[5] = {"file1", "file2", "file3", "file4", "file5"};

	for(int i = 0; i < 5; i++){
		
		fd[i] = open(files[i], O_CREAT, O_RDWR);
		
		if(fd[i] == -1){
			perror("failed");
			return 0;
		}

		printf("file created successully with fd : %d\n", fd[i]);
	}

	while(1){

	}
	
	return 0;
}
/*
============================================================================
Output:
sameer@sameer-ACERPCHLY:/proc/20455$ cd /proc/20455/fd
sameer@sameer-ACERPCHLY:/proc/20455/fd$ ls -l
total 0
lrwx------ 1 sameer sameer 64 Sep  1 14:50 0 -> /dev/pts/0
lrwx------ 1 sameer sameer 64 Sep  1 14:50 1 -> /dev/pts/0
lrwx------ 1 sameer sameer 64 Sep  1 14:50 2 -> /dev/pts/0
lr-x------ 1 sameer sameer 64 Sep  1 14:50 3 -> /home/sameer/Study/Systems/handsOn/file1
lr-x------ 1 sameer sameer 64 Sep  1 14:50 4 -> /home/sameer/Study/Systems/handsOn/file2
lr-x------ 1 sameer sameer 64 Sep  1 14:50 5 -> /home/sameer/Study/Systems/handsOn/file3
lr-x------ 1 sameer sameer 64 Sep  1 14:50 6 -> /home/sameer/Study/Systems/handsOn/file4
lr-x------ 1 sameer sameer 64 Sep  1 14:50 7 -> /home/sameer/Study/Systems/handsOn/file5
============================================================================
*/

