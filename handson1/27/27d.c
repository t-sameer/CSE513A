/*
============================================================================
Name : 27d.c
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
    char *argv[] = {"ls", "-Rl", NULL};
    execv("/bin/ls", argv);
    perror("execv failed");
    return 1;
}

/*
============================================================================
Output:
sameer@sameer-ACERPCHLY:~/Study/Systems/handsOn/27$ gcc 27d.c -o 27d
sameer@sameer-ACERPCHLY:~/Study/Systems/handsOn/27$ ./27d
.:
total 84
-rwxrwxr-x 1 sameer sameer 16000 Sep  7 14:40 27a
-rw-rw-r-- 1 sameer sameer   820 Sep  7 14:45 27a.c
-rwxrwxr-x 1 sameer sameer 16000 Sep  7 14:48 27b
-rw-rw-r-- 1 sameer sameer   918 Sep  7 14:45 27b.c
-rwxrwxr-x 1 sameer sameer 16000 Sep  7 14:47 27c
-rw-rw-r-- 1 sameer sameer   843 Sep  7 14:48 27c.c
-rwxrwxr-x 1 sameer sameer 16056 Sep  7 14:50 27d
-rw-rw-r-- 1 sameer sameer   951 Sep  7 14:50 27d.c
drwxrwxr-x 2 sameer sameer  4096 Sep  7 14:47 test

./test:
total 0
============================================================================
*/

