#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char *argv[])
{
  int pid;
  printf(1, "priority of parent is set to 15\n");
  pid = fork();
  setpriority(15);
  if (pid == 0){
	printf(1, "priority of child is set to 20\n");
	setpriority(20);
	while(getpriority() > 15) asm("nop");
	printf(1, "priority of child is: %d\n", getpriority());
        exit(0);
  }
  wait(0);
  printf(1, "parent runs\n", getpriority());

  exit(0);
}
