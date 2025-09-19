/*
============================================================================
Name : Q9.c
Author : Sameer
Description : Write a program to print the following information about a given file.
              a. inode
              b. number of hard links
              c. uid
              d. gid
              e. size
              f. block size
              g. number of blocks
              h. time of last access
              i. time of last modification
              j. time of last change
Date: 20th Aug, 2025.
============================================================================
*/

#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

int main() {
    char* fname = "9.c";
    struct stat status;

    stat(fname, &status);

    printf("Inode is: %lu\n", status.st_ino);
    printf("Number of hard links: %lu\n", status.st_nlink);
    printf("UID is: %u\n", status.st_uid);
    printf("GID is: %u\n", status.st_gid);
    printf("File size is: %ld Bytes\n", status.st_size);
    printf("Size of block is: %ld bytes\n", status.st_blksize);
    printf("Number of blocks are: %ld\n", status.st_blocks);
    printf("Time of last access is: %s", ctime(&status.st_atime));
    printf("Time of last modification is: %s", ctime(&status.st_mtime));
    printf("Time of last change is: %s", ctime(&status.st_ctime));

    return 0;
}
/*
============================================================================
Output:
sameer@sameer-ACERPCHLY:~/Study/Systems/handsOn/9$ gcc 9.c -o 9
sameer@sameer-ACERPCHLY:~/Study/Systems/handsOn/9$ ./9
Inode is: 6327672
Number of hard links: 1
UID is: 1000
GID is: 1000
File size is: 1369 Bytes
Size of block is: 4096 bytes
Number of blocks are: 8
Time of last access is: Sun Sep  7 03:55:39 2025
Time of last modification is: Sun Sep  7 03:55:36 2025
Time of last change is: Sun Sep  7 03:55:36 2025
============================================================================
*/ 
