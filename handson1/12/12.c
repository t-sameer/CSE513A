/* 
============================================================================ 
Name : Q12.c 
Author : Sameer 
Description: Write a program to find out the opening mode of a file. Use fcntl. 
Date: 20th Aug, 2025. 
============================================================================ 
*/

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int main()
{
    int fd = open("file", O_RDONLY);

    int fmode = fcntl(fd, F_GETFL);
    printf("%d\n", fmode);
 
    int accessMode = fmode & O_ACCMODE;
    printf("%d\n", accessMode);

    if (accessMode == O_RDWR) {
        printf("File is of read and write mode\n");
    } 
    
    else if (accessMode == O_WRONLY) {
        printf("File is of write only mode\n");
    } 
    
    else if (accessMode == O_RDONLY) {
        printf("File is of read only mode\n");
    } 
    
    else {
        printf("Unknown file access mode\n");
    }

    return 0;
}
/*
============================================================================ 
Output:
sameer@sameer-ACERPCHLY:~/Study/Systems/handsOn/12$ gcc 12.c -o 12
sameer@sameer-ACERPCHLY:~/Study/Systems/handsOn/12$ ./12 file
32768
0
File is of read only mode
============================================================================ 
*/

