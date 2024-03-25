#include <pthread.h>
extern void __VERIFIER_atomic_begin(void);
extern void __VERIFIER_atomic_end(void);

int counter = 0;

void increase() {
	int state;
	while (1) {
		__VERIFIER_atomic_begin();
		state++;
		if (state > 3) {
			state = 0;
			counter++;
		}
		__VERIFIER_atomic_end();
	}
}

void decrease() {
	while (1) {
		__VERIFIER_atomic_begin();
		if (counter > 0)
			counter--;
		__VERIFIER_atomic_end();
	}
}

void main() {
	pthread_t id1, id2;
	
	pthread_create(&id1, 0, increase, 0);
	pthread_create(&id2, 0, decrease, 0);
	
	pthread_join(id1, 0);
	pthread_join(id2, 0);
	
	return 0;
	ERROR:
	return -1;
	
}