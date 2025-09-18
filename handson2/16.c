#include<stdio.h>
#include<unistd.h>

int main(){
	int fd1[2];
	int fd2[2];
	
	pipe(fd1);
	pipe(fd2);

	char bufc[100];
	char bufp[100];

	if(!fork()){
		close(0);
		close(1);
		dup(fd1[0]);
		dup(fd2[1]);
		close(fd1[1]);
		close(fd2[0]);
		read(fd1[0], bufc, sizeof(bufc));
		printf("the printed from parent file is %s", bufc);
		write(fd2[1], "Dorara", 7);
	}
	else{
		close(0);
		close(1);
		dup(fd1[1]);
		dup(fd2[0]);
		close(fd1[0]);
		close(fd2[1]);
		read(fd2[0], bufp, sizeof(bufp));
		printf("the msg from child is :%s", bufp);
		write(fd1[1], "PapaDorara", 11);
	}
	return 0;
}
		

