extern unsigned __VERIFIER_nondet_int();
extern void abort(void);
void __VERIFIER_assume(int cond) {
    if (!cond)
        abort();
}

int schedule(__t0_active, __t1_active, __t2_active) {
    if (__t1_active && __t2_active) {
        return 2;
    } else {
        return __VERIFIER_nondet_int();
    }
}

int main() {
    int pc[] = { 0, 0, 0 };
    int __t0_active = 1;
    int __t1_active = 0;
    int __t2_active = 0;
    int __t0_joins_t1 = 0;
    int __t0_joins_t2 = 0;

    int x = 0;
    
    while (1) {
        int next_thread = schedule(__t0_active, __t1_active, __t2_active);

        __VERIFIER_assume(0 <= next_thread && next_thread < 3);
        __VERIFIER_assume(__t0_active || next_thread != 0);
        __VERIFIER_assume(__t1_active || next_thread != 1);
        __VERIFIER_assume(__t2_active || next_thread != 2);

        __VERIFIER_assume(!(__t1_active && __t0_joins_t1) || next_thread != 0);
        __VERIFIER_assume(!(__t2_active && __t0_joins_t2) || next_thread != 0);

        if (next_thread == 0) {
            switch (pc[0]) {
                case 0: __t1_active = 1; pc[0] = 1; continue;
                case 1: __t2_active = 1; pc[0] = 2; continue;
                case 2: if (__t1_active) { __t0_joins_t1 = 1; } else { __t0_joins_t1 = 0; pc[0] = 3; } continue;
                case 3: if (__t2_active) { __t0_joins_t2 = 1; } else { __t0_joins_t2 = 0; pc[0] = 4; } continue;
                case 4: if (x < 2) goto ERROR; pc[0] = 5; continue;
                case 5: __t0_active = 0; pc[0] = -1; continue;
                default: goto ERROR;
            }
        } else if (next_thread == 1) {
            switch (pc[1]) {
                case 0: x = 0; pc[1] = 1; continue;
                case 1: x = x + 1; pc[1] = -1; __t1_active = 0; continue;
                default: goto ERROR;
            }
        } else if (next_thread == 2) {
            switch (pc[2]) {
                case 0: x = x + 1; pc[2] = 1; continue;
                case 1: x = x + 1; pc[2] = -1; __t2_active = 0; continue;
                default: goto ERROR;
            }
        }
    }

    return 0;
    ERROR: return -1;
}
