#include <stdio.h>
#include <pthread.h>

int x = 0;

void *thr1(void *args) {
    x = 1;
    x = 2;
    x = 3; 
    x = 4;
    x = 5;
    x = 6;
}
void *thr2(void *args) {
    x = 7;
    x = 8;
    x = 9;
    x = 10;
    x = 11;
    x = 12;
    if (x < 12) assert(0);
}

int main() {
  pthread_t t1 = 0, t2 = 0;
  pthread_create(&t1, 0, thr1, 0);
  pthread_create(&t2, 0, thr2, 0);
  pthread_join(t1, 0);
  pthread_join(t2, 0);
  return 0;
}
