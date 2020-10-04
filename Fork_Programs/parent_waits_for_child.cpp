#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main()
{
  int pid;
  pid=fork();
  if(pid<0)
  {
    printf("Child Process could not be created");
    exit(-1);
  }
  else if(pid==0)
  {
    printf("Child ID:%d,Parent ID:%d\n",getpid(),getppid());
  }
  else
  {
    wait(NULL);
    printf("Parent Process");
  }
  return 0;
}
