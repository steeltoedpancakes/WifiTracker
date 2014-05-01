
//this controls all aspects of wifi tracker 
// must be sudo

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
void sigusr1_handler(int signum) {  // handler for SIGUSR1
  //start
  system("airmon-ng start wlan0");
  system("airodump-ng mon0 -w taco");
  //run database setup?? no do it in bash
} 

void sigalrm_handler(int signum) {  
  //needs work still sigalrm is killing task
  //restart
  system("ps -face | grep airodump | awk '{print $2}' | xargs kill -9");
  //maybe we make backup instead?
  system("rm taco*");
  system("airodump-ng mon0 -w taco");
  // nightly cleanup
  system("sqlite3 wifiData.db 'ALTER TABLE wifiData.db . address RENAME TO address %x %r %Z'");
}  
void sigusr2_handler(int signum) {
  //stop
  system("ps -face | grep airodump | awk '{print $2}' | xargs kill -9");
}
void sigbus_handler(int signum){
  //wipe DB compleatly 
  system("echo  i_wiped_it");
  //system(rm WifiData.db);
}

int main(int argc, char *argv[]) {
  signal(SIGUSR2, sigusr2_handler);
  signal(SIGUSR1, sigusr1_handler);
  signal(SIGALRM, sigalrm_handler);
  signal(SIGBUS, sigbus_handler);
  
  while(1){}


}

