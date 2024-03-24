#include <pthread.h>

pthread_t id1, id2;
int found1 = 0, found2 = 0;
int id;

void task1() {
	int state = 0;
	while (1) {
		if (state < 7) {
			state = state + 1;
		} else {
			state = 0;
		}
		
		if (state == 7) {
			found1 = 1;
		}
	}
}

void task2() {
	int state = 0;
	while (1) {
		if (state < 7) {
			state = state + 1;
		} else {
			state = 0;
		}
		
		if (state == 7) {
			found2 = 1;
		}
	}
}

void main() {
	pthread_create(&id1, 0, task1, 0);
	pthread_create(&id2, 0, task2, 0);
	
	while (1) {
		int found = found1 && found2;
	}
	
	pthread_join(id1, 0);
	pthread_join(id2, 0);
	
	ERROR:
	return (-1);
}