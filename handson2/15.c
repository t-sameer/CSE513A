#include<stdio.h>
#include<unistd.h>

int main(){
	int fd[2];
	pipe(fd);
	char buf[100];

	if(!fork()){
		close(0);
		dup(fd[0]);
		close(fd[1]);
		read(fd[0], buf, sizeof(buf));
		printf("This is child: %s", buf);
	}
	else{
		close(1);
		dup(fd[1]);
		close(fd[0]);
		write(fd[1], "Dorara", 7);
	}
	return 0;
}
