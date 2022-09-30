#include<stdio.h>
#include <unistd.h>
int main()
{
	int pid = fork();
	// child process:
	if(pid == 0)
	{
          printf("\nChild Process id is : %d and parent process id is : %d \n",getpid(),getppid());
	}
	// parent process :
	else
	{
          sleep(4);
          printf("\nParent Process id is : %d \n",getpid());
	}	
}

