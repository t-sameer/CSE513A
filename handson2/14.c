#include<stdio.h>
#include<unistd.h>

int main(){

	int i, j, fd[2];
	char buf[100];
	i = pipe(fd);

	int byteswrite = write(fd[1], "Dorara", 7);
	read(fd[0], buf, byteswrite);
	printf("%s", buf);
	return 0;
}
