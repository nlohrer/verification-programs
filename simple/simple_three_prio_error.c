extern unsigned __VERIFIER_nondet_int();
extern void abort(void);
#include <assert.h>
void reach_error() { assert(0); }
void __VERIFIER_assume(int cond) {
    if (!cond)
        abort();
}

int schedule(__t0_active, __t1_active, __t2_active, __t3_active, __t0_joins_t1, __t0_joins_t2, __t0_joins_t3) {
    if (__t1_active && __t2_active) {
        return 2; // semantically not correct right now: t0 should still be schedulable in this situation
    } else if (__t1_active && __t3_active) {
        return 3;
    } else if (__t2_active && __t3_active) {
        return 3;
    } else {
        int next_thread = __VERIFIER_nondet_int();
        __VERIFIER_assume(
            (0 <= next_thread && next_thread < 4) &&
            (__t0_active || next_thread != 0) &&
            (__t1_active || next_thread != 1) &&
            (__t2_active || next_thread != 2) &&
            (__t3_active || next_thread != 3) &&
            (!(__t1_active && __t0_joins_t1) || next_thread != 0) &&
            (!(__t2_active && __t0_joins_t2) || next_thread != 0) &&
            (!(__t3_active && __t0_joins_t3) || next_thread != 0)
            );
        return next_thread;
    }
}

int main() {
    int pc[] = { 0, 0, 0, 0 };
    int __t0_active = 1;
    int __t1_active = 0;
    int __t2_active = 0;
    int __t3_active = 0;
    int __t0_joins_t1 = 0;
    int __t0_joins_t2 = 0;
    int __t0_joins_t3 = 0;

    int x = 0;
    
    while (1) {
        int next_thread = schedule(__t0_active, __t1_active, __t2_active, __t3_active, __t0_joins_t1, __t0_joins_t2, __t0_joins_t3);


        if (next_thread == 0) {
            switch (pc[0]) {
                case 0: __t1_active = 1; pc[0] = 1; continue;
                case 1: __t2_active = 1; pc[0] = 2; continue;
                case 2: __t3_active = 1; pc[0] = 3; continue;
                case 3: if (__t1_active) { __t0_joins_t1 = 1; } else { __t0_joins_t1 = 0; pc[0] = 4; } continue;
                case 4: if (__t2_active) { __t0_joins_t2 = 1; } else { __t0_joins_t2 = 0; pc[0] = 5; } continue;
                case 5: if (__t3_active) { __t0_joins_t3 = 1; } else { __t0_joins_t3 = 0; pc[0] = 6; } continue;
                case 6: if (x < 3) reach_error(); pc[0] = 7; continue;
                case 7: __t0_active = 0; pc[0] = -1; continue;
                default: reach_error();
            }
        } else if (next_thread == 1) {
            switch (pc[1]) {
                case 0: x = 0; pc[1] = 1; continue;
                case 1: x = x + 1; pc[1] = -1; __t1_active = 0; continue;
                default: reach_error();
            }
        } else if (next_thread == 2) {
            switch (pc[2]) {
                case 0: x = x + 1; pc[2] = 1; continue;
                case 1: x = x + 1; pc[2] = -1; __t2_active = 0; continue;
                default: reach_error();
            }
        } else if (next_thread == 3) {
            switch (pc[3]) {
                case 0: x = 1; pc[3] = 1; continue;
                case 1: x = x + 1; pc[3] = 2; continue;
                case 2: x = x + 1; pc[3] = -1; __t3_active = 0; continue;
                default: reach_error();
            }
        }
    }
    return 0;
}
