#include <stdio.h>
#include <pthread.h>

int x = 0;

void *thr1(void *args) {
    x++;
}
void *thr2(void *args) {
    x++;
}
void thr3(void *args) {
    x++;
    if (x >= 3) assert(0);
}

int main() {
  pthread_t t1 = 0, t2 = 0, t3 = 0;
  pthread_create(&t1, 0, thr1, 0);
  pthread_create(&t2, 0, thr2, 0);
  pthread_create(&t3, 0, thr3, 0);
  pthread_join(t1, 0);
  pthread_join(t2, 0);
  pthread_join(t3, 0);
  return 0;
}