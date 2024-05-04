int _assert(int condition) { if (!condition) ERROR: return -1; }

#include <pthread.h>
pthread_mutex_t l1;
pthread_mutex_t l2;
int counter = 0;
int l1_owner = 0;
int l2_owner = 0;

extern void __VERIFIER_atomic_begin(void);
extern void __VERIFIER_atomic_end(void);

int task1() {
    while (1) {
        pthread_mutex_lock(&l1);
        l1_owner = 1;
        _assert(l2_owner == 0);
        pthread_mutex_lock(&l2);
        l2_owner = 1;
        counter++;

        __VERIFIER_atomic_start();
        pthread_mutex_unlock(&l1);
        pthread_mutex_unlock(&l2);
        l1_owner = 0;
        l2_owner = 0;
        __VERIFIER_atomic_end();
    }
    return 0;
}

int task2() {
    pthread_mutex_lock(&l2);
    l2_owner = 2;
    _assert(l1_owner == 0);
    pthread_mutex_lock(&l1);
    l1_owner = 2;
    counter++;

    __VERIFIER_atomic_start();
    pthread_mutex_unlock(&l1);
    pthread_mutex_unlock(&l2);
    l1_owner = 0;
    l2_owner = 0;
    __VERIFIER_atomic_end();
    return 0;
}

int main() {
    pthread_t id1, id2;
    pthread_mutex_init(&l1, 0);
    pthread_mutex_init(&l2, 0);

    pthread_create(&id1, 0, task1, 0);
    pthread_create(&id2, 0, task2, 0);

    pthread_join(id1, 0);
    pthread_join(id2, 0);

	_assert(counter > 10);
    return 0;
}
