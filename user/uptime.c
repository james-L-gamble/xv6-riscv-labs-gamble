#include "kernel/types.h"


#include "user/user.h"


int main(){

  int current_uptime = uptime();


  printf("The current uptime, in clock cycles, since system start is: %d\n",current_uptime);

  exit(0);
  

}
    
