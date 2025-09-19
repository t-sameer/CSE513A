/*
============================================================================
Name : Q14.c
Author : Sameer
Description : Write a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to
verify whether the data is available within 10 seconds or not (check in $man 2 select).
Date: 22nd Aug, 2025.
============================================================================
*/

#include<stdio.h>
#include<sys/select.h>

int main(){
	fd_set rdfd;
	struct timeval tv;
	int retval;

	FD_ZERO(&rdfd);
	FD_SET(0, &rdfd);

	tv.tv_sec = 10;
	tv.tv_usec = 0;

	retval = select(1, &rdfd ,NULL ,NULL, &tv);
      	
	if(retval == -1){
		perror("Error Occured");
	}

	else if(retval){
		printf("Data is available for reading within 10 seconds.");
	}
	
	else{
		printf("data is not available for reading within 10 seconds.");
	}
}
/*
============================================================================
Output:
sameer@sameer-ACERPCHLY:~/Study/Systems/handsOn/13$ ./13

Data is available for reading within 10 seconds.
============================================================================
*/

