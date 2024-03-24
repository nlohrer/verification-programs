#include <pthread.h>

pthread_t id1, id2;
int i=1, j=1;

int main() {
  pthread_create(&id1, 0, t1, 0);
  pthread_create(&id2, 0, t2, 0);
  
  pthread_join(id1, 0);
  pthread_join(id2, 0);
  
  if (j > 8) {
	goto ERROR;
  }
  
  return (0);
  ERROR:
  return (-1);
}

void t1() {
	i+=j;
	i+=j;
}

void t2() {
	j+=i;
	j+=i;
}