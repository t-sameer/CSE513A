/*
============================================================================
Name : Q25.c
Author : Sameer
Description : Write a program to create three child processes. The parent 
              should wait for a particular child (use waitpid system call).
Date: 27th Aug, 2025.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int a, b, c;

    if (!(a = fork())) {
        sleep(1);
    }
    else if (!(b = fork())) {
        sleep(5);
    }
    else if (!(c = fork())) {
        sleep(10);
    }
    else {
        waitpid(b, NULL, 0);
	printf("waiting for child with pid %d\n", b);
    }

    return 0;
}
/*
============================================================================
Output:
sameer@sameer-ACERPCHLY:~/Study/Systems/handsOn/25$ gcc 25.c -o 25
sameer@sameer-ACERPCHLY:~/Study/Systems/handsOn/25$ ./25
waiting for child with pid 8364
============================================================================
*/

