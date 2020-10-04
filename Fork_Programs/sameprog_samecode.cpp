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
  else
  {
    printf("Child ID is:%d,My Parent ID is:%d\n",getpid(),getppid());
  }
  return 0;
}
