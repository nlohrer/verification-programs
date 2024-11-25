#include <pthread.h>
int x = 0;
extern void abort(void);
#include <assert.h>
void reach_error() { assert(0); }

void *task1(void *arg) {
    x = 0;
    x++;
}

void *task2(void *arg) {
    x++;
    x++;
}

void *task3(void *arg) {
    x = 1;
    x++;
    x++;
}

int main() {
    pthread_t id1, id2, id3;

    pthread_create(&id1, (void *) 0, task1, (void *) 0);
    pthread_create(&id2, (void *) 0, task2, (void *) 0);
    pthread_create(&id3, (void *) 0, task3, (void *) 0);

    pthread_join(id1, (void *) 0);
    pthread_join(id2, (void *) 0);
    pthread_join(id3, (void *) 0);

    if (x < 3) { reach_error(); } // error should be reachable

    return 0;
}
