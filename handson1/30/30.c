/*
============================================================================
Name : Q30.c
Author : Sameer
Description : Write a program to run a script at a specific time using a Daemon process.
Date: 28th Aug, 2025.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/stat.h>

int main() {
    pid_t pid = fork();
    if (pid < 0) exit(1);
    if (pid > 0) exit(0);

    if (setsid() < 0) exit(1);
    umask(0);
    chdir("/");

    close(0);
    close(1);
    close(2);

    while (1) {
        time_t now = time(NULL);
        struct tm *t = localtime(&now);

        if (t->tm_hour == 14 && t->tm_min == 23) {
            execl("/bin/sh", "sh", "/home/sameer/Study/Systems/handsOn/30/hello.sh", (char *)NULL);
        }

        sleep(1);
    }

    return 0;
}
/*
============================================================================
Output:
sameer@sameer-ACERPCHLY:~/Study/Systems/handsOn/30$ gcc 30.c -o daemon2test
sameer@sameer-ACERPCHLY:~/Study/Systems/handsOn/30$ sudo ./daemon2test
[sudo] password for sameer:
sameer@sameer-ACERPCHLY:~/Study/Systems/handsOn/30$ cat log.txt
Hello this script ran at Sun Sep  7 01:12:39 PM IST 2025
Hello this script ran at Sun Sep  7 01:17:06 PM IST 2025
Hello this script ran at Sun Sep  7 02:23:00 PM IST 2025
============================================================================
*/

