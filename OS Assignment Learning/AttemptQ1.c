#include<stdio.h>
#include<fcntl.h>
#include<errno.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<string.h>
#include<sys/wait.h>
#include<sys/signal.h>
#include <sys/time.h>


void sigterm_handler(int signum, siginfo_t *info, void *c){
	int len = strlen("Inside the SIGTERM's signal handler\n");
	write(fileno(stdout), "Inside the SIGTERM's signal handler\n", len);
	// printf("Here: %d\n", info->si_int);
	printf("Here: %d\n", info->si_value);
	printf("Here String: %s\n", (char*)info->si_ptr);
	// printf("Here str: %s\n", info->si_);
	
	sleep(1);
	// exit(0);
}

void S1(){
	printf("Inside S1\n");
	printf("Registering the signal handler for SIGTERM.\n");
	// signal(SIGTERM,sigterm_handler); 
	struct sigaction my_action;
	my_action.sa_flags = SA_SIGINFO;
	my_action.sa_handler = &sigterm_handler;
	
	sigaction(SIGTERM, &my_action, NULL);
}

void SR(pid_t p)
{
	char y[20];
	sprintf(y, "%d", p);

	execl("./sk", y);
}

int main(){
	pid_t pid;
	
	if((pid=fork())<0){
		perror("Error in calling Fork system call\n");
		exit(1);
	}

	else if(pid==0){
		S1();
		pause();
	}

	else{
		sleep(2);
		printf("\nInside the parent\n");
		printf("Destination Process ID for kill: %d\n", pid);
		
		pid_t pidSR, pidST;
		if((pidSR=fork())<0){
			perror("Error in calling Fork system call\n");
			exit(1);
		}

		else if(pidSR==0){
			SR(pid);
			// exit(0);
		}

		else{
			int s;
			waitpid(pidSR, &s, 0);
			printf("\nhere Inside\n");
		}

		// union sigval sigdata;
		// sigdata.sival_int = 5;
		
		// printf("Using the kill system call to invoke SIGTERM's handler\n");
		// sigqueue (pid, SIGTERM, sigdata);
		// sleep(2);
		printf("Using the kill system call to invoke SIGTERM's handler\n");
		kill(pid,SIGTERM);
	}
	return 0;
}