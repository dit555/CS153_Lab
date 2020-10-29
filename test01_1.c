#include "types.h"
#include "stat.h"
#include "user.h"



int
main(int argc, char *argv[])
{
  int i;
  int pid;
  int status;
  
  if (pid = fork()){
	exit(6);
  }
  else{
	wait(&status);
	printf(1, "fork exited with status: ", status, "\n");
  }
}
