#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>

int x, y, z; 

void *sum(){
	z=y+x;
	return NULL;
}

int main(){
	pid_t child;
	pthread_t thread;

    // Initializing the global variables
	x=10, y=20, z=0;

	/* MOVE THE FOLLOWING LINES INTO THEIR PROPER PLACES...
		
		
    */

   /* Add code under every comment to demonstrate differences between child and thread */


// Name: Wentao Du			Student Number:251030528

    // create child process
	pid_t pid;
	pid = fork();
	// check for child creation error
	if(pid<0){
		printf("ERROR while creating child process");
	}
	// in parent:
	if(pid>0){
	// wait for child, and print value of z
		while(wait(NULL)==-1){
		}
		printf("Using a fork(), the value of z in the parent process is: %d\n", z); //value of z after the fork process won't change;
		// create thread, wait for it to complete, then print value of z
		pthread_t tid;
		if(pthread_create(&tid, NULL,sum,NULL)){
			printf("main function: errno number is %d\n", errno);
			exit(1);
		}
		pthread_join(tid,NULL);
		printf("Using a thread, the value of z is: %d\n", z); //value of z after passing to the thread will change
	}


	// in child:
	if(pid==0){
	// sum x and y and store it in z
	sum();
	printf("Using a fork(), the value of z in the child process is: %d\n", z); 
	}
	// print value of z

	return 0;
}
