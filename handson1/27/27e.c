/*
============================================================================
Name : 27b.c
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
    execvp("ls", argv);
    perror("execvp failed");
    return 1;
}

/*
============================================================================
Output:
sameer@sameer-ACERPCHLY:~/Study/Systems/handsOn/27$ gcc 27e.c -o 27e
sameer@sameer-ACERPCHLY:~/Study/Systems/handsOn/27$ ./27e
.:
total 104
-rwxrwxr-x 1 sameer sameer 16000 Sep  7 14:40 27a
-rw-rw-r-- 1 sameer sameer   820 Sep  7 14:45 27a.c
-rwxrwxr-x 1 sameer sameer 16000 Sep  7 14:48 27b
-rw-rw-r-- 1 sameer sameer   918 Sep  7 14:45 27b.c
-rwxrwxr-x 1 sameer sameer 16000 Sep  7 14:47 27c
-rw-rw-r-- 1 sameer sameer   843 Sep  7 14:48 27c.c
-rwxrwxr-x 1 sameer sameer 16056 Sep  7 14:50 27d
-rw-rw-r-- 1 sameer sameer  1292 Sep  7 14:51 27d.c
-rwxrwxr-x 1 sameer sameer 16056 Sep  7 14:52 27e
-rw-rw-r-- 1 sameer sameer   946 Sep  7 14:52 27e.c
drwxrwxr-x 2 sameer sameer  4096 Sep  7 14:47 test

./test:
total 0
============================================================================
*/
