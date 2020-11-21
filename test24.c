#include "types.h"
#include "stat.h"
#include "user.h"

void stuff(int k);

int main(int argc, char *argv[]){

	int pid;
	pid = fork();
	setpriority(15);
	if(pid == 0){
		stuff(50000);
		printf(1, "child with has finished doing stuff \n");
	}
	else{
		setpriority(10);
		stuff(1000);
		printf(1, "arrive time of child: %d\n", getarrivetime(pid));
		printf(1, "exit time of child: %d\n", getlasttime(pid));
		printf(1, "turnaround time of child: %d\n", turnaroundtime(pid));
		wait(0);
	}
	exit(0);
}

void stuff(int k){
	int i,j;
	for (i = 0; i < 50000; i++){
		for (j = 0; j < k; j++)	
			asm("nop");	
	}
	
}
