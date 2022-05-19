#include <stdio.h>
#include<stdio.h>
#include<fcntl.h>
#include<errno.h>
#include <sys/types.h>
#include <unistd.h>
#include<stdlib.h>
#include <sys/stat.h>
#include<string.h>
#include<sys/wait.h>
#include <sys/signal.h>
#include<sys/time.h>
#include<time.h>



void sigalrm_handler(int signum){
	int len = strlen("Inside the SIGALRM's signal handler\n");
	write(fileno(stdout), "Inside the SIGALRM's signal handler\n", len);
	// sleep(1);
	// exit(0);
}

int main(int argc, char const *argv[])
{
  unsigned hi, lo;
  __asm__ __volatile__ ("rdtsc" : "=a"(lo), "=d"(hi));
  printf("%u %u\n", hi, lo);
  // sleep(2);
  // printf("\nInside SR process\n");
  // printf("Destination Process ID for kill from Inside SR: %d\n", atoi(argv[0]));

  // printf("\nGenerating a random number\n");
  // int randomNo;
  // __asm__(
  //     "rdrand  %[randomNo]"
  //     : [randomNo] "=r" (randomNo)         
  // );

  // printf("The random number generated is: %d\n", randomNo);  

  // union sigval sigdata;
  // sigdata.sival_int = randomNo;

  // printf("Using the sigqueue system call to invoke SIGTERM's handler\n");
  // sigqueue (atoi(argv[0]), SIGTERM, sigdata);

  // printf("Registering the handler for SIGALRM\n");
  // signal(SIGALRM,sigalrm_handler);
  // printf("Using the alarm system call to invoke SIGALRM's handler\n");
  // alarm(2);
  // sleep(2);
}