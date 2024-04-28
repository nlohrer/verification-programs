#include <pthread.h>
pthread_mutex_t l1;
pthread_mutex_t l2;
int v = 0;

void task1() {
	pthread_mutex_lock(&l1);
	pthread_mutex_lock(&l2);
	v++;
	pthread_mutex_unlock(&l1);
	pthread_mutex_unlock(&l2);
}

void task2() {
	pthread_mutex_lock(&l1);
	pthread_mutex_lock(&l2);
	v++;
	pthread_mutex_unlock(&l1);
	pthread_mutex_unlock(&l2);
}

void main() {
	pthread_t id1, id2;
	pthread_mutex_init(&l1, 0);
	pthread_mutex_init(&l2, 0);

	pthread_create(&id1, 0, task1, 0);
	pthread_create(&id2, 0, task2, 0);

	pthread_join(id1, 0);
	pthread_join(id2, 0);

	if (v < 2) goto ERROR;

	return 0;
	ERROR:
	return -1;

}