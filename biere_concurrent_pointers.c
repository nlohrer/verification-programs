#include <pthread.h>

pthread_t id1, id2;
int found1 = 0, found2 = 0;
int id;
int turn;

void task(int *found) {
	int state = 0;
	while (1) {
		if (state < 7) {
			state = state + 1;
		}
		if (state == 7) {
			*found = 1;
			return;
		}
	}
}

void main() {
	int turn = 0;
	pthread_create(&id1, 0, task, &found1);
	pthread_create(&id2, 0, task, &found2);
	
	pthread_join(id1, 0);
	pthread_join(id2, 0);
	
	if (!(found1 && found2)) goto ERROR;
	return (0);
	ERROR:
	return (-1);
}