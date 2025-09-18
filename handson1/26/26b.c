/*
============================================================================
Name : Q26b.c
Author : Sameer
Description :Write a program to execute an executable program.
             a. use some executable program
             b. pass some input to an executable program. (for example execute an executable of $./a.out name)
Date: 28th Aug, 2025.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    printf("Executing a.out\n");

    char *path = "./a.out";

    char *args[] = {"a.out", "Sameer", NULL};

    execv(path, args);

    return 0;
}

/*
============================================================================
Output:
sameer@sameer-ACERPCHLY:~/Study/Systems/handsOn/26$ gcc 26b.c -o 26
sameer@sameer-ACERPCHLY:~/Study/Systems/handsOn/26$ ./26
Executing a.out
Argument passed is:  Sameer!
============================================================================
*/


