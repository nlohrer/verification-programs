#include <pthread.h>
int l1 = 0;
int v = 0;

void lock_c(int *l, int id) {
	while (1) {
		if (*l == 0) {
			*l = id;
			return;
		}
	}
}

void unlock_c(int *l, int id) {
	while (1) {
		if (*l == id) {
			*l = 0;
			return;
		}
	}
}

void task1() {
	lock_c(&l1, 1);
	v++;
	unlock_c(&l1, 1);
}

void task2() {
	lock_c(&l1, 2);
	v++;
	unlock_c(&l1, 2);
}

int main() {
	pthread_t id1, id2;
	
	pthread_create(&id1, 0, task1, 0);
	pthread_create(&id2, 0, task2, 0);
	
	pthread_join(id1, 0);
	pthread_join(id2, 0);
	
	if (v < 2) goto ERROR;
	
	return 0;
	ERROR:
	return -1;
	
}