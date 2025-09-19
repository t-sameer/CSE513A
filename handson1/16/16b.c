/*
============================================================================
Name : Q16a.c
Author : Sameer
Description : Write a program to perform mandatory locking.
              a. Implement write lock
              b. Implement read lock
Date: 20th Aug, 2025.
============================================================================
*/
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
int main(int argc, char *argv[])
{
    int fd = open(argv[1], O_RDONLY);
    
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    struct flock lock = {F_RDLCK, 0, 0, 0, 0};
    
    fcntl(fd, F_SETLKW, &lock);
    printf("File is locked now.\n");
    getchar();  

    lock.l_type = F_UNLCK;
    printf("File is unlocked\n");

    fcntl(fd, F_SETLKW, &lock);
    
    close(fd);
    
    return 0; 
}

/*
============================================================================
Output:
sameer@sameer-ACERPCHLY:~/Study/Systems/handsOn/16$ gcc 16b.c -o 16b
sameer@sameer-ACERPCHLY:~/Study/Systems/handsOn/16$ ./16b
sameer@sameer-ACERPCHLY:~/Study/Systems/handsOn/16$ ./16b 16b.c
File is locked now.

File is unlocked
============================================================================
*/

