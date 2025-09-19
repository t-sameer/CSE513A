/*
============================================================================
Name : Q17a.c
Author : Sameer
Description : Write a program to simulate online ticket reservation. Implement write lock
Write a program to open a file, store a ticket number and exit. Write a separate program, to
open the file, implement write lock, read the ticket number, increment the number and print
the new ticket number then close the file.
Date: 23th Aug, 2025.
============================================================================
*/
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]) {


    int ticket_number;

    printf("Enter the ticket number: ");
    scanf("%d", &ticket_number);

    int fd = open(argv[1], O_WRONLY | O_CREAT, 0644);
    
    if (fd == -1) {
        perror("Error opening the file");
        return 1;
    }

    char ticket_str[50];
    snprintf(ticket_str, sizeof(ticket_str)," %d\n", ticket_number);

    write(fd, ticket_str, strlen(ticket_str));
    
    printf("ticket generated");

    close(fd);

    return 0;
}
/*
============================================================================
Output:
sameer@sameer-ACERPCHLY:~/Study/Systems/handsOn/17$ gcc 17a.c -o 17a
sameer@sameer-ACERPCHLY:~/Study/Systems/handsOn/17$ ./17a ticket.txt
Enter the ticket number: 102
ticket generated
============================================================================
*/
