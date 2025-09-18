/*
============================================================================
Name : 1B.c
Author : Sameer
Description : 1. Create the following types of a files using (i) shell command (ii) system call
a. soft link (symlink system call)
b. hard link (link system call)
c. FIFO (mkfifo Library Function or mknod system call)
Date: 28th Aug, 2025.
============================================================================
*/

#include<stdio.h>
#include<unistd.h>

int main(void){
    int flag = 0;

    const char *target = "file1.txt";
    const char *name = "hardlinktofile";

    flag = link(target, name);

    if(flag == 0){
        printf("hard link created successfully");
    }
    else{
        printf("hard link creation unsuccessful");
    }
    
    return 0;
}
/*
============================================================================
Output:
sameer@sameer-ACERPCHLY:~/Study/Systems/handsOn/1$ gcc 1B.c -o 1B
sameer@sameer-ACERPCHLY:~/Study/Systems/handsOn/1$ ./1B
hard link created successfullysameer@sameer-ACERPCHLY:~/Study/Systems/handsOn/1$ ls
1A  1A.c  1B  1B.c  1C  1C.c  file1  file1.txt  hardlinktofile  linktofile1  myfifo
sameer@sameer-ACERPCHLY:~/Study/Systems/handsOn/1$
============================================================================
*/

