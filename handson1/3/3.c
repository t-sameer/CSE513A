/*
============================================================================
Name : 3.c
Author : Sameer
Description : Write a program to create a file and print the file descriptor value. Use creat ( ) system call
Date: 26th Aug, 2025.
============================================================================
*/
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd;

    fd = creat("myfile.txt", 0644);

    if (fd == -1) {
        perror("creat");
        return 1;
    }

    printf("File created successfully. File descriptor: %d\n", fd);

    close(fd);
    return 0;
}
/*
============================================================================
Output:
sameer@sameer-ACERPCHLY:~/Study/Systems/handsOn/3$ gcc 3.c -o 3
sameer@sameer-ACERPCHLY:~/Study/Systems/handsOn/3$ ./3
File created successfully. File descriptor: 3
============================================================================
*/


