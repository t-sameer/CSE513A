/*
============================================================================
Name : Q26.c
Author : Sameer
Description :Write a program to execute an executable program.
             a. use some executable program
             b. pass some input to an executable program. (for example execute an executable of $./a.out name)
Date: 28th Aug, 2025.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Executing ls...\n");

    char *path = "/bin/ls";
    char *args[] = {"ls", "-l", NULL};

    execv(path, args);
    return 0;
}
/*
============================================================================
Output:
sameer@sameer-ACERPCHLY:~/Study/Systems/handsOn/26$ gcc 26.c -o 26
sameer@sameer-ACERPCHLY:~/Study/Systems/handsOn/26$ ./26
Executing ls...
total 20
-rwxrwxr-x 1 sameer sameer 16048 Sep  7 02:36 26
-rw-rw-r-- 1 sameer sameer   792 Sep  7 02:36 26.c
============================================================================
*/
