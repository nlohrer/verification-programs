#include <pthread.h>
extern void __VERIFIER_atomic_begin(void);
extern void __VERIFIER_atomic_end(void);

int l1 = 0, l2 = 0;
int v = 0;

void lock(int *l, int id) {
	while (1) {
		__VERIFIER_atomic_begin();
		if (*l == 0) {
			*l = id;
			return;
		}
		__VERIFIER_atomic_end();
	}
}

void unlock(int *l, int id) {
	while (1) {
		__VERIFIER_atomic_begin();
		if (*l == id) {
			*l = 0;
			return;
		}
		__VERIFIER_atomic_end();
	}
}

void task1() {
	lock(&l2, 1);
	lock(&l1, 1);
	v++;
	unlock(&l1, 1);
	unlock(&l2, 1);
}

void task2() {
	lock(&l2, 2);
	lock(&l1, 2);
	v++;
	unlock(&l1, 2);
	unlock(&l2, 2);
}

void main() {
	pthread_t id1, id2;
	
	pthread_create(&id1, 0, task1, 0);
	pthread_create(&id2, 0, task2, 0);
	
	pthread_join(id1, 0);
	pthread_join(id2, 0);
	
	if (v != 2) goto ERROR;
	
	return 0;
	ERROR:
	return -1;
	
}