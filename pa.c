#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int gVar = 100;

int main() {
  pid_t firstChild = fork(), secondChild;
  if(firstChild == 0) {
    gVar++;
    printf("%d\n", gVar);
  }
  else {
    secondChild = fork();
    if(secondChild == 0) {
      gVar--;
      printf("%d\n", gVar);
    }
    else
      printf("%d\n", gVar);
  }
  return 0;
}
