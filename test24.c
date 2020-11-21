#include "types.h"
#include "stat.h"
#include "user.h"

void stuff();

int main(int argc, char *argv[]){

	int pid;
	pid = fork();
	setpriority(15);
	if(pid == 0){
		stuff();
		printf(1, "child with has finished doing stuff \n");
	}
	else{
	setpriority(11);
		stuff();
		printf(1, "arrive time of child: %d\n", getarrivetime(pid));
		printf(1, "exit time of child: %d\n", getlasttime(pid));
		printf(1, "turnaround time of child: %d\n", turnaroundtime(pid));
	}
	exit(0);
}

void stuff(){
	int i,j;
	for (i = 0; i < 50000; i++){
		for (j = 0; j < 1000; j++)	
			asm("nop");	
	}
	
}
