/*
============================================================================
Name : 27a.c
Author : Sameer
Description : 27. Write a program to execute ls -Rl by the following system calls
a. execl
b. execlp
c. execle
d. execv
e. execvp
Date: 26th Aug, 2025.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>

int main() {
    execl("/bin/ls", "ls", "-Rl", NULL);
    perror("execl failed");
    return 1;
}
/*
============================================================================
Output:
sameer@sameer-ACERPCHLY:~/Study/Systems/handsOn/27$ ./27a
.:
total 20
-rwxrwxr-x 1 sameer sameer 16000 Sep  7 14:40 27a
-rw-rw-r-- 1 sameer sameer   651 Sep  7 14:40 27a.c
============================================================================
*/

