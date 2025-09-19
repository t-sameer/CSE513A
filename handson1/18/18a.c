/*
============================================================================
Name : Q18a.c
Author : Sameer
Description : Write a program to perform Record locking.
a. Implement write lock
b. Implement read lock
Create three records in a file. Whenever you access a particular record, first lock it then modify/access
to avoid race condition.
Date: 27th Aug, 2025.
============================================================================
*/
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

struct record
{
    int recordID;
    int data;
};

int main()
{
    int fd = open("/home/sameer/Study/Systems/handsOn/18/records.txt", O_RDWR);
	if(fd == -1) perror("file opening failed:");
    struct flock wrlock = {F_WRLCK, SEEK_SET, 0, sizeof(struct record), getpid()};
    
    int recordID;
    printf("Enter record to lock \n");
    
    scanf("%d", &recordID);
    
    if(recordID>3){
	    printf("Record not found");
    }

    else{
	printf("locking record %d\n", recordID);
	
	wrlock.l_start = (recordID-1)*sizeof(struct record);
    	wrlock.l_len = sizeof(struct record);
    	fcntl(fd, F_SETLKW, &wrlock);
	
	printf("record %d is locked\n\n", recordID);	
	
	struct record rec;

	lseek(fd, (recordID - 1)* sizeof(struct record), SEEK_SET);
	read(fd, &rec, sizeof(struct record));

	printf("current record is %d: %d\n", rec.recordID, rec.data);
	
	printf("enter new value for record %d\n", recordID);
	scanf("%d", &rec.data);

	lseek(fd, (recordID - 1)* sizeof(struct record), SEEK_SET);
	write(fd, &rec, sizeof(struct record));

	printf("Record %d updated to data: %d\n\n", recordID, rec.data);
	printf("Press enter to unlock\n");

    	getchar();
    	getchar();
	

    	wrlock.l_type = F_UNLCK;
    	fcntl(fd, F_SETLKW, &wrlock);
    	printf("record %d is unlocked\n",recordID);
    }
    return 0;
}
/*
============================================================================
Output:
sameer@sameer-ACERPCHLY:~/Study/Systems/handsOn/18$ gcc 18a.c -o 18a
sameer@sameer-ACERPCHLY:~/Study/Systems/handsOn/18$ ./18a
Enter record to lock 
2
locking record
record 2 is locked
Press enter to unlock it
============================================================================
*/
