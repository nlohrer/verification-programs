#include <pthread.h>
pthread_mutex_t l1;
pthread_mutex_t l2;

extern void __VERIFIER_atomic_begin(void);
extern void __VERIFIER_atomic_end(void);

int v = 0;
int __ADDED_l1_owner = 0;
int __ADDED_l2_owner = 0;

void task1() {
	pthread_mutex_lock(&l1);
	__ADDED_l1_owner = 1;
	if (__ADDED_l2_owner != 0) goto ERROR;
	pthread_mutex_lock(&l2);
	__ADDED_l2_owner = 1;
	v++;
	__VERIFIER_atomic_begin();
	pthread_mutex_unlock(&l1);
	__ADDED_l1_owner = 0;
	pthread_mutex_unlock(&l2);
	__ADDED_l2_owner = 0;
	__VERIFIER_atomic_end();
	return;
	ERROR:
	return -1;
}

void task2() {
	pthread_mutex_lock(&l1);
	__ADDED_l1_owner = 2;
	if (__ADDED_l2_owner != 0) goto ERROR;
	pthread_mutex_lock(&l2);
	__ADDED_l2_owner = 2;
	v++;
	__VERIFIER_atomic_begin();
	pthread_mutex_unlock(&l1);
	__ADDED_l1_owner = 0;
	pthread_mutex_unlock(&l2);
	__ADDED_l2_owner = 0;
	__VERIFIER_atomic_end();
	return;
	ERROR:
	return -1;
}

void task3() {
	pthread_mutex_lock(&l2);
	__ADDED_l2_owner = 3;
	v++;
	__VERIFIER_atomic_begin();
	pthread_mutex_unlock(&l1);
	__ADDED_l2_owner = 0;
	__VERIFIER_atomic_end();
	return;
}

void main() {
	pthread_t id1, id2, id3;
	pthread_mutex_init(&l1, 0);
	pthread_mutex_init(&l2, 0);

	pthread_create(&id1, 0, task1, 0);
	pthread_create(&id2, 0, task2, 0);
	pthread_create(&id3, 0, task1, 0);

	pthread_join(id1, 0);
	pthread_join(id2, 0);
	pthread_join(id3, 0);

	if (v < 3) goto ERROR;

	return 0;
	ERROR:
	return -1;

}