#include <pthread.h>

pthread_t id1, id2;
int found1 = 0, found2 = 0;
int looped1 = 0, looped2 = 0;
int fair1 = 0, fair2 = 0;
int id;
int turn;

extern void __VERIFIER_atomic_begin(void);
extern void __VERIFIER_atomic_end(void);

void task1() {
	int state = 0;
	while (1) {
		__VERIFIER_atomic_begin();
		fair1 = 1;
		if (state < 3) {
			state = state + 1;
		} else {
			state = 0;
		}
		if (state == 3) {
			found1 = 1;
		}
		looped1 = state == 0;
		__VERIFIER_atomic_end();
	}
}

void task2() {
	int state = 0;
	while (1) {
		__VERIFIER_atomic_begin();
		fair2 = 1;
		if (state < 3) {
			state = state + 1;
		} else {
			state = 0;
		}
		if (state == 3) {
			found2 = 1;
		}
		looped2 = state == 0;
		__VERIFIER_atomic_end();
	}
}

void main() {
	int turn = 0;
	pthread_create(&id1, 0, task1, 0);
	pthread_create(&id2, 0, task2, 0);
	
	while (1) {
		__VERIFIER_atomic_begin();
		int found = found1 && found2;
		int looped = looped1 && looped2;
		int fair = fair1 && fair2;
		__VERIFIER_atomic_end();
		if (looped && fair && !found) goto ERROR;
	}
	
	pthread_join(id1, 0);
	pthread_join(id2, 0);
	
	ERROR:
	return (-1);
}