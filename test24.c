#include "types.h"
#include "stat.h"
#include "user.h"

void stuff();

int main(int argc, char *argv[]){

	int pid;
	pid = fork();
	if(pid == 0){
		stuff();
		printf(1, "child with has finished doing stuff \n");
		exit(0);
	}
	wait(0);
	printf(1, "arrive time of child: %d\n", getarrivetime(pid));
	printf(1, "exit time of child: %d\n", getlasttime(pid));
	printf(1, "turnaround time of child: %d\n", turnaroundtime(pid));
	exit(0);
}

void stuff(){
	int i;
	int stuff = 0;
	for (i = 0; i < 10000; i++)
		stuff++;
}
