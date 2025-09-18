/*
============================================================================
Name : 27c.c
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

int main(int argc, char *argv[], char *envp[]) {
    execle("/bin/ls", "ls", "-Rl", "test/", NULL, envp);
    perror("execle failed");
    return 1;
}
/*
============================================================================
Output:
sameer@sameer-ACERPCHLY:~/Study/Systems/handsOn/27$ gcc 27c.c -o 27c
sameer@sameer-ACERPCHLY:~/Study/Systems/handsOn/27$ ./27c
test/:
total 0
============================================================================
*/

