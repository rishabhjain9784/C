#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>
int main(void)
{
    int pfds[2];
    int pfds1[2];
    char buf[30];
    pipe(pfds);
    if (!fork()) 
	{
        printf(" CHILD: writing to the pipe\n");
        write(pfds[1], "OS", 3);
        printf(" CHILD: exiting\n");
        exit(0);
    } 
	else 
	{
        printf("PARENT: reading from pipe\n");
        read(pfds[0], buf, 6);
        printf("PARENT: \"%s\"\n", buf);
        wait(NULL);
    }
    pipe(pfds1);
    if (!fork()) 
	{
        printf("PARENT: writing from pipe\n");
        write(pfds1[1], "lab", 3);
        printf(" PARENT: exiting\n");
        wait(NULL);
       
    } 
	else 
	{
        printf(" CHILD: READING to the pipe\n");
        read(pfds1[0], buf, 6);
        printf("CHILD: \"%s\"\n", buf);
        exit(0);
    }
    return 0;
}

