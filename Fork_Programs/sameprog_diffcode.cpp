#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{
  int pid;
  pid=fork();
  if(pid<0)
  {
    printf("Child process could not be created.");
    exit(-1);
  }
  else if(pid==0)
  {
    printf("Child ID:%d,Parent ID:%d",getpid(),getppid());
  }
  else
  {
    printf("Parent Process\n");
  }
  return 0;
}
