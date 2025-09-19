/*
============================================================================
Name : Q18b.c
Author : Sameer
Description : Write a program to perform Record locking.
a. Implement write lock
b. Implement read lock
Create three records in a file. Whenever you access a particular record, first lock it then modify/access
to avoid race condition.
Date: 28th Aug, 2025.
============================================================================
*/
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

struct record
{
    int recordID;
    int value;
};

int main()
{
    int fd = open("/home/sameer/Study/Systems/handsOn/18/records.txt", O_RDONLY);
    if(fd == -1) perror("file opening failed:");
    
    struct flock rdlock = {F_RDLCK, SEEK_SET, 0, sizeof(struct record), getpid()};
    
    int recordID;
    printf("Enter record to lock \n");
    scanf("%d", &recordID);

    if(recordID>3)printf("Record not found");
    
    else{
	printf("locking record\n");
    	rdlock.l_start = (recordID-1)*sizeof(struct record);
    	rdlock.l_len = sizeof(struct record);
    	fcntl(fd, F_SETLKW, &rdlock);
    
	printf("record %d id locked Enter to unlock it\n", recordID);
    
	getchar();
    	getchar();
    	
	rdlock.l_type = F_UNLCK;
    	fcntl(fd, F_SETLKW, &rdlock);
    	
	printf("record is unlocked\n");
    }
    return 0;
}
/*
============================================================================
Output:
sameer@sameer-ACERPCHLY:~/Study/Systems/handsOn/18$ gcc 18b.c -o 18b
sameer@sameer-ACERPCHLY:~/Study/Systems/handsOn/18$ ./18b
Enter record to lock 
2
locking record
============================================================================
*/
