/*
============================================================================
Name : Q28.c
Author : Sameer
Description : Write a program to get maximum and minimum real time priority.
Date: 28th Aug, 2025.
============================================================================
*/
#include <stdio.h>
#include <sched.h>

int main()
{
    printf("Maximum priority FIFO %d\n Minimum priority FIFO %d\n", sched_get_priority_max(SCHED_FIFO), sched_get_priority_min(SCHED_FIFO));
    printf("Maximum priority RR %d\n Minimum priority RR %d\n", sched_get_priority_max(SCHED_RR), sched_get_priority_min(SCHED_RR));
    printf("Maximum priority OTHER %d\n Minimum priority OTHER %d\n", sched_get_priority_max(SCHED_OTHER), sched_get_priority_min(SCHED_OTHER));
    return 0;
}
/*
============================================================================
sameer@sameer-ACERPCHLY:~/Study/Systems/handsOn/28$ gcc 28.c -o 28
sameer@sameer-ACERPCHLY:~/Study/Systems/handsOn/28$ ./28
Maximum priority FIFO 99
 Minimum priority FIFO 1
Maximum priority RR 99
 Minimum priority RR 1
Maximum priority OTHER 0
 Minimum priority OTHER 0
============================================================================

*/
