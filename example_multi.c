#include <unistd.h>

int main() {
  int a = 0;
  int pid = fork();
  
  if (pid == 0) {
	goto ERROR;
  }

  return (0);
  ERROR:
  return (-1);
}

