#include <pthread.h>
int x = 0;
extern void __assert_fail(const char *__assertion, const char *__file, unsigned int __line, const char *__function);

void *task1(void *arg) {
    x = 0;
    x++;
}

void *task2(void *arg) {
    x++;
    x++;
}

int main() {
    pthread_t id1, id2;

    pthread_create(&id1, (void *) 0, task1, (void *) 0);
    pthread_create(&id2, (void *) 0, task2, (void *) 0);

    pthread_join(id1, (void *) 0);
    pthread_join(id2, (void *) 0);

    if (x < 2) {__assert_fail("0", "simple_two.c", 24, __extension__ __PRETTY_FUNCTION__);} // error should be reachable

    return 0;
}
