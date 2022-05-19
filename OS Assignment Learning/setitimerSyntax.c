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

/*
void sigalrm_handler(int signum){
	int len = strlen("Inside the SIGALRM's signal handler\n");
	write(fileno(stdout), "Inside the SIGALRM's signal handler\n", len);
	sleep(1);
	// exit(0);
}

int main(int argc, char const *argv[])
{
  sleep(2);
  printf("\nInside SR process\n");
  printf("Destination Process ID for kill from Inside SR: %d\n", atoi(argv[0]));

//   union sigval sigdata;
//   sigdata.sival_int = 5;

//   printf("Using the sigqueue system call to invoke SIGTERM's handler\n");
//   sigqueue (atoi(argv[0]), SIGTERM, sigdata);

  printf("Registering the handler for SIGALRM\n");
  signal(SIGALRM,sigalrm_handler);
  printf("Using the alarm system call to invoke SIGALRM's handler\n");
  struct itimerval it;
  it.it_value.tv_sec = 1;
  int x = setitimer(ITIMER_REAL, NULL, NULL);
  pause();
  printf("%d\n", x);
  sleep(2);
}
*/

#define INTERVAL 500        /* number of milliseconds to go off */

/* function prototype */
void DoStuff(void);

int main(int argc, char *argv[]) {

  struct itimerval it_val;  /* for setting itimer */

  /* Upon SIGALRM, call DoStuff().
   * Set interval timer.  We want frequency in ms, 
   * but the setitimer call needs seconds and useconds. */
  if (signal(SIGALRM, (void (*)(int)) DoStuff) == SIG_ERR) {
    perror("Unable to catch SIGALRM");
    exit(1);
  }
  it_val.it_value.tv_sec = 1;
  it_val.it_value.tv_usec = 0;   
  it_val.it_interval.tv_sec=10;
  it_val.it_interval.tv_usec=0;
  if (setitimer(ITIMER_REAL, &it_val, NULL) == -1) {
    perror("error calling setitimer()");
    exit(1);
  }

  while (1) 
    pause();

}

/*
 * DoStuff
 */
void DoStuff(void) {

  printf("Timer went off.\n");

}



  
