#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char *argv[])
{
  int pid, pid2;
  int status;

  pid = fork();
  if (pid == 0){
	printf(1, "exiting pid %d with 6\n", getpid());
	exit(6);
  }
  else if (pid > 0) {  
  	pid2 = wait(&status);
  	printf(1, "child %d exited with status: %d\n", pid2, status);
  }
  else{
	printf(1, "fork failure\n");
  }
  exit(0);
}
