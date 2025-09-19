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
static inline unsigned long long read_tsc() {
    unsigned int lo, hi;
    __asm__ volatile("rdtsc" : "=a"(lo), "=d"(hi));
    return ((unsigned long long)hi << 32) | lo;
}

int main() {
    unsigned long long t1, t2;
    pid_t pid;
    
    t1 = read_tsc();
    
    pid = getpid();
    
    t2 = read_tsc();
    
    printf("Process ID: %d\n", pid);

    printf("Time taken (cycles) : %llu\n", t2 - t1);
    
    return 0;
}

/*
============================================================================
sameer@sameer-ACERPCHLY:~/Study/Systems/handsOn/19$ ./19
Process ID: 16251
Time taken (cycles) : 154198
============================================================================
*/

