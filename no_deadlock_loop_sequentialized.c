extern int __VERIFIER_nondet_int(void);

int main() {
	int l1 = 0;
	int l2 = 0;
	int t1_can_progress = 1;
	int t2_can_progress = 1;
	int counter = 0;	// this counter gets changed by both threads so that the state space of the program is not trivial
	
	int t1_location = 10;
	int t2_location = 20;
	while (1) {
			while(1) {
				if (__VERIFIER_nondet_int()) break;
				if (t1_location == 10) {
					// t1 tries to acquire l1
					if (l1 != 0) {
						t1_can_progress = 0;
						break;
					}
					t1_can_progress = 1;
					l1 = 1;
					t1_location = 11;
				}
				if (__VERIFIER_nondet_int()) break;
				if (t1_location == 11) {
					// t1 tries to acquire l2
					if (l2 != 0) {
						t1_can_progress = 0;
						break;
					}
					t1_can_progress = 1;
					l2 = 1;
					t1_location = 12;
				}
				if (__VERIFIER_nondet_int()) break;
				if (t1_location == 12) {
					// t1 increases the counter and releases l1 and l2
					counter++;
					l1 = 0;
					l2 = 0;
					t1_location = 10;
				}
			}
			
			while(1) {
				if (__VERIFIER_nondet_int()) break;
				if (t2_location == 20) {
					// t2 tries to acquire l1
					if (l1 != 0) {
						t2_can_progress = 0;
						break;
					}
					t2_can_progress = 1;
					l1 = 2;
					t2_location = 21;
				}
				if (__VERIFIER_nondet_int()) break;
				if (t2_location == 21) {
					// t2 tries to acquire l2
					if (l2 != 0) {
						t2_can_progress = 0;
						break;
					}
					t2_can_progress = 1;
					l2 = 2;
					t2_location = 22;
				}
				if (__VERIFIER_nondet_int()) break;
				if (t2_location == 22) {
					// t2 increases the counter and releases l1 and l2
					counter++;
					l1 = 0;
					l2 = 0;
					t2_location = 20;
				}
			}
			// Deadlock detected if neither thread can can make progress
			if (!t1_can_progress && !t2_can_progress) ERROR: return -1;
	}
	return 0;
}
