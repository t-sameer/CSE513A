/*
============================================================================
Name        : 20.c
Author      : Sameer
Description : Find out the priority of your running program.
              Modify the priority with nice command.
Date        : 28th Aug, 2025.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/resource.h>

int main()
{   
    int priority;

    priority = getpriority(PRIO_PROCESS, 0);
    printf("Current priority is: %d\n", priority);

    int new_val = nice(10); 
    setpriority(PRIO_PROCESS, 0, new_val);    
    printf("New priority after nice(10): %d\n", getpriority(PRIO_PROCESS, 0));

    return 0;
}
/*
============================================================================
Output: 
sameer@sameer-ACERPCHLY:~/Study/Systems/handsOn/20$ gcc 20.c -o 20
sameer@sameer-ACERPCHLY:~/Study/Systems/handsOn/20$ ./20
Current priority is: 0
New priority after nice(10): 10
============================================================================
*/
