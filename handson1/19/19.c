/*
============================================================================
Name        : 19.c
Author      : Sameer
Description : Write a program to find out time taken to execute getpid system call. Use time stamp counter.
Date        : 26th Aug, 2025
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

int main() {
    struct timeval start, end;
    pid_t pid;

    gettimeofday(&start, NULL);

    printf("pid: %d\n", getpid());

    gettimeofday(&end, NULL);

    long seconds = end.tv_sec - start.tv_sec;
    long useconds = end.tv_usec - start.tv_usec;

    printf("Time taken: %lds %ldusec\n", seconds, useconds);

    return 0;
}

/*
============================================================================
sameer@sameer-ACERPCHLY:~/Study/Systems/handsOn/19$ ./19
pid: 8789
Time taken: 0s 70usec
============================================================================
*/

