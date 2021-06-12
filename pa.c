#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int gVar = 100;

int main() {
  pid_t firstChild, secondChild;
  firstChild = fork();
  if(firstChild == 0) {
    printf("%d", ++gVar);
  }
  else {
    secondChild = fork();
    if(secondChild == 0){
      printf("%d", --gVar);
    } else {
      sleep(1);
      printf("%d", gVar);
    }
  }
  return 0;
}
