/*
============================================================================
Name : Q29.c
Author : Sameer
Description : Write a program to get scheduling policy and modify the scheduling policy (SCHED_FIFO,
              SCHED_RR).
Date: 28th Aug, 2025.
============================================================================
*/
#include <stdio.h>
#include <sched.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    int pid = getpid();
    int curr_policy;
    struct sched_param parameter;

    curr_policy = sched_getscheduler(pid);

    if (curr_policy == SCHED_OTHER)
        printf("Current scheduling policy is SCHED_OTHER\n");
    else if (curr_policy == SCHED_FIFO)
        printf("Current scheduling policy is SCHED_FIFO\n");
    else if (curr_policy == SCHED_RR)
        printf("Current scheduling policy is SCHED_RR\n");
    else
        printf("Unknown scheduling policy\n");

    printf("Switching to FIFO\n");

    parameter.sched_priority = 1;
    sched_setscheduler(pid, SCHED_FIFO, &parameter);
    curr_policy = sched_getscheduler(pid);

    if (curr_policy == SCHED_OTHER)
        printf("Current scheduling policy is SCHED_OTHER\n");
    else if (curr_policy == SCHED_FIFO)
        printf("Current scheduling policy is SCHED_FIFO\n");
    else if (curr_policy == SCHED_RR)
        printf("Current scheduling policy is SCHED_RR\n");
    else
        printf("Unknown scheduling policy\n");

    printf("Switching to RR\n");

    parameter.sched_priority = 1;
    sched_setscheduler(pid, SCHED_RR, &parameter);
    curr_policy = sched_getscheduler(pid);

    if (curr_policy == SCHED_OTHER)
        printf("Current scheduling policy is SCHED_OTHER\n");
    else if (curr_policy == SCHED_FIFO)
        printf("Current scheduling policy is SCHED_FIFO\n");
    else if (curr_policy == SCHED_RR)
        printf("Current scheduling policy is SCHED_RR\n");
    else
        printf("Unknown scheduling policy\n");

    return 0;
}
/*
============================================================================
Output:
sameer@sameer-ACERPCHLY:~/Study/Systems/handsOn/29$ gcc 29.c -o 29
sameer@sameer-ACERPCHLY:~/Study/Systems/handsOn/29$ sudo ./29
Current scheduling policy is SCHED_OTHER
Switching to FIFO
Current scheduling policy is SCHED_FIFO
Switching to RR
Current scheduling policy is SCHED_RR
============================================================================
*/
