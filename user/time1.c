#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"


int main(int argc, char *argv[]){

  //Display the program's instructions if called with no argument
  if(argc < 2){
    printf("Usage: prints the execution time of a process, in clock cycles.\n");
    exit(1);
  }

  int pid;
  int preExecTime;
  int postExecTime;

  //Iterate over all arguments after "time1"
  for(int i = 1; i < argc; i++){

    preExecTime = uptime(); //Store time before second program's execution
    printf("Time: %d ticks\n",preExecTime);
    pid = fork(); //Fork process to keep time1 running

    //If this process is a fork, execute the argument as a program
    if(pid == 0){    
      exec(argv[i],argv);
      wait(0);
    }

    postExecTime = uptime() - preExecTime; //Compute execution time
    
    printf("Elapsed time: %d ticks\n",postExecTime);
    exit(0);
  }


  exit(0);

}
