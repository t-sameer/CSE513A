/*
============================================================================
Name : 1C.c
Author : Sameer
Description : 1. Create the following types of a files using (i) shell command (ii) system call
a. soft link (symlink system call)
b. hard link (link system call)
c. FIFO (mkfifo Library Function or mknod system call)
Date: 28th Aug, 2025.
============================================================================
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

int main() {
    if (mkfifo("myfifo", 0666) == -1) {
        perror("mkfifo failed");
    }
    return 0;
}
/*
============================================================================
Output:
sameer@sameer-ACERPCHLY:~/Study/Systems/handsOn/1$ gcc 1C.c -o 1C
sameer@sameer-ACERPCHLY:~/Study/Systems/handsOn/1$ ./1C
sameer@sameer-ACERPCHLY:~/Study/Systems/handsOn/1$ ls
1A.c  1B.c  1C  1C.c  myfifo
============================================================================
*/

