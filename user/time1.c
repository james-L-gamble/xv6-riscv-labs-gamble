#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"


int main(int argc, char *argv[]){

  if(argc < 2){
    printf("Usage: prints the execution time of a process, in clock cycles.\n");
    exit(1);
  }

  int pid;
  int preExecTime;
  int postExecTime;
  for(int i = 1; i < argc; i++){

    preExecTime = uptime();
    printf("Time: %d ticks\n",preExecTime);
    pid = fork();

    if(pid == 0){    
      exec(argv[i],argv);
      wait(0);
    }

    postExecTime = uptime() - preExecTime;
    printf("Elapsed time: %d ticks\n",postExecTime);
    exit(0);
  }


  exit(0);

}
