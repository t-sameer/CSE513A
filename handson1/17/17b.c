/*
============================================================================
Name : Q17b.c
Author : Sameer
Description : Write a program to simulate online ticket reservation. Implement write lock
Write a program to open a file, store a ticket number and exit. Write a separate program, to
open the file, implement write lock, read the ticket number, increment the number and print
the new ticket number then close the file.
Date: 23th Aug, 2025.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int fd = open("ticket.txt", O_RDWR);
    if(fd == -1) { 
    	perror("Error opening file");
    }

    struct flock fl = {F_WRLCK, SEEK_SET, 0, 0, 0};
    
    fcntl(fd, F_SETLKW, &fl);
    printf("File is locked\n");

    char buffer[100];
    
    int n = read(fd, buffer, sizeof(buffer));
    int ticketNum = atoi(buffer); 
    ticketNum++;
    printf("New ticket number is: %d\n", ticketNum);

    sprintf(buffer, "%d", ticketNum); 
    
    lseek(fd, 0, SEEK_SET);

    write(fd, buffer, sizeof(buffer));

    fl.l_type = F_UNLCK;
    fcntl(fd, F_SETLKW, &fl);
    printf("file is unlocked\n");
    close(fd);
    return 0;
}
/*
============================================================================
Output:
sameer@sameer-ACERPCHLY:~/Study/Systems/handsOn/17$ ./17b
File is locked
New ticket number is: 103
file is unlocked
============================================================================
* /
