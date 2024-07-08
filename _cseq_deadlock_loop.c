#include <stdlib.h>
typedef int __cs_mutex_t;
#define pthread_mutex_t __cs_mutex_t
typedef int __cs_cond_t;
#define pthread_cond_t __cs_cond_t
typedef int __cs_t;
#define pthread_t __cs_t
/* Translation information */
// Main thread
unsigned int __cs_pc_1;
// task1_0 thread
unsigned int __cs_pc_2;
_Bool __cs_activethread_2;
void * __cs_args_2;
// task2_0 thread
unsigned int __cs_pc_3;
_Bool __cs_activethread_3;
void * __cs_args_3;
int __cs_simulate;
/* Predefined functions type 1 */
void __cseq_error()
{
    ERROR: goto ERROR;
}

void __VERIFIER_assume(int i)
{
    while (!i);
    return;
}

_Bool __VERIFIER_nondet_bool()
{
    _Bool i;
    return i;
}

char __VERIFIER_nondet_char()
{
    char i;
    return i;
}

int __VERIFIER_nondet_int()
{
    int i;
    return i;
}

unsigned int __VERIFIER_nondet_uint()
{
    unsigned int i; __VERIFIER_assume(i>=0);
    return i;
}

/* Predefined functions type 2 */
//void * __cs_safe_malloc(size_t size)
//{
//    void * ptr = malloc(size);
//    __VERIFIER_assume(ptr);
//    return ptr;
//}

//void * __cs_unsafe_malloc(size_t size)
//{
//    if(__VERIFIER_nondet_bool())
//        return 0;
//    return malloc(size);
//}

void __cs_init_scalar(void *var, unsigned int size)
{
    if (size == sizeof(int))
        *(int *)var = __VERIFIER_nondet_int();
    else {
        char * ptr = (char *)var;
        // size_t j;
        //for (j=0; j<size; j++)
        //  ptr[j] = __cs_nondet_char();
    }
}

/* Global variables */
__cs_mutex_t l1;
__cs_mutex_t l2;
int counter = 0;
int task2_0(void *arg)
{
    if (__cs_simulate == 0 && __cs_pc_3 == 0) __cs_simulate = 1;
    if (__cs_simulate == 1)
    if (__VERIFIER_nondet_bool()) {__cs_pc_3 = 0; __cs_simulate = 2;} else    {
            __VERIFIER_assume(l1 == 0);
            l1 = 3;
    }
    if (__cs_simulate == 0 && __cs_pc_3 == 1) __cs_simulate = 1;
    if ((__cs_simulate == 1) && (l1 == 3))
    if (__VERIFIER_nondet_bool()) {__cs_pc_3 = 1; __cs_simulate = 2;} else    {
            __VERIFIER_assume(l2 == 0);
            l2 = 3;
    }
    if (__cs_simulate == 0 && __cs_pc_3 == 2) __cs_simulate = 1;
    if ((__cs_simulate == 1) && (l1 == 3) && (l2 == 3))
    if (__VERIFIER_nondet_bool()) {__cs_pc_3 = 2; __cs_simulate = 2;} else    {
            counter++;
    }
    if (__cs_simulate == 0 && __cs_pc_3 == 3) __cs_simulate = 1;
    if ((__cs_simulate == 1) && (l1 == 3) && (l2 == 3))
    if (__VERIFIER_nondet_bool()) {__cs_pc_3 = 3; __cs_simulate = 2;} else    {
            l1 = 0;
    }
    if (__cs_simulate == 0 && __cs_pc_3 == 4) __cs_simulate = 1;
    if ((__cs_simulate == 1) && (l1 == 3))
    if (__VERIFIER_nondet_bool()) {__cs_pc_3 = 4; __cs_simulate = 2;} else    {
            l2 = 0;
    }
    if (__cs_simulate == 1 || (__cs_simulate == 0 && __cs_pc_3 == 5))
    {
        __cs_pc_3 = 5;
        __cs_simulate = 2;
    }
}
int main_thread()
{
    static __cs_t __cs_l_main_id1;
    static __cs_t __cs_l_main_id2;
    if (__cs_simulate == 0 && __cs_pc_1 == 0) __cs_simulate = 1;
    if (__cs_simulate == 1)
    if (__VERIFIER_nondet_bool()) {__cs_pc_1 = 0; __cs_simulate = 2;} else    {
            l1 = 0;
    }
    if (__cs_simulate == 0 && __cs_pc_1 == 1) __cs_simulate = 1;
    if (__cs_simulate == 1)
    if (__VERIFIER_nondet_bool()) {__cs_pc_1 = 1; __cs_simulate = 2;} else    {
            l2 = 0;
    }
    if (__cs_simulate == 0 && __cs_pc_1 == 2) __cs_simulate = 1;
    if (__cs_simulate == 1)
    if (__VERIFIER_nondet_bool()) {__cs_pc_1 = 2; __cs_simulate = 2;} else    {
            __cs_activethread_2 = 1;
            __cs_args_2 = 0;
    }
    if (__cs_simulate == 0 && __cs_pc_1 == 3) __cs_simulate = 1;
    if (__cs_simulate == 1)
    if (__VERIFIER_nondet_bool()) {__cs_pc_1 = 3; __cs_simulate = 2;} else    {
            __cs_activethread_3 = 1;
            __cs_args_3 = 0;
    }
    if (__cs_simulate == 0 && __cs_pc_1 == 4) __cs_simulate = 1;
    if (__cs_simulate == 1)
    if (__VERIFIER_nondet_bool()) {__cs_pc_1 = 4; __cs_simulate = 2;} else    {
            __VERIFIER_assume(__cs_pc_2 == 4);
    }
    if (__cs_simulate == 0 && __cs_pc_1 == 5) __cs_simulate = 1;
    if (__cs_simulate == 1)
    if (__VERIFIER_nondet_bool()) {__cs_pc_1 = 5; __cs_simulate = 2;} else    {
            __VERIFIER_assume(__cs_pc_3 == 5);
    }
    if (__cs_simulate == 1 || (__cs_simulate == 0 && __cs_pc_1 == 6))
    {
        __cs_pc_1 = 6;
        __cs_simulate = 2;
    }
}
int task1_0(void *arg)
{
    if (__cs_simulate == 0 && __cs_pc_2 == 0) __cs_simulate = 1;
    if (__cs_simulate == 1)
    if (__VERIFIER_nondet_bool()) {__cs_pc_2 = 0; __cs_simulate = 2;} else    {
            __VERIFIER_assume(l2 == 0);
            l2 = 2;
    }
    if (__cs_simulate == 0 && __cs_pc_2 == 1) __cs_simulate = 1;
    if ((__cs_simulate == 1) && (l2 == 2))
    if (__VERIFIER_nondet_bool()) {__cs_pc_2 = 1; __cs_simulate = 2;} else    {
            __VERIFIER_assume(l1 == 0);
            l1 = 2;
    }
    if (__cs_simulate == 0 && __cs_pc_2 == 2) __cs_simulate = 1;
    if ((__cs_simulate == 1) && (l2 == 2) && (l1 == 2))
    if (__VERIFIER_nondet_bool()) {__cs_pc_2 = 2; __cs_simulate = 2;} else    {
            l1 = 0;
    }
    if (__cs_simulate == 0 && __cs_pc_2 == 3) __cs_simulate = 1;
    if ((__cs_simulate == 1) && (l2 == 2))
    if (__VERIFIER_nondet_bool()) {__cs_pc_2 = 3; __cs_simulate = 2;} else    {
            l2 = 0;
    }
    if (__cs_simulate == 1 || (__cs_simulate == 0 && __cs_pc_2 == 4))
    {
        __cs_pc_2 = 4;
        __cs_simulate = 2;
    }
}
/*   Thread simulation */
int main()
{
  __cs_simulate = 0;
  __cs_pc_1 = 0;
  __cs_pc_2 = 0;
  __cs_activethread_2 = 0;
  __cs_pc_3 = 0;
  __cs_activethread_3 = 0;
  while (1)
  {
    __cs_simulate = 0;
    main_thread();
    __cs_simulate = 0;
    if (__cs_activethread_2) task1_0(__cs_args_2);
    __cs_simulate = 0;
    if (__cs_activethread_3) task2_0(__cs_args_3);
  }
}
