#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char *argv[])
{
  int pid;
  pid = fork();
  //setpriority(13);
  if (pid == 0){
	//setpriority(11);
	printf(1, "priority of child is: %d\n", getpriority());
	exit(0);
  }
  wait(0);
  printf(1, "priority of parent is: %d\n", getpriority());

  exit(0);
}
