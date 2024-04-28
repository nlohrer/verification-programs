extern int __VERIFIER_nondet_int(void);

int main() {
	int counter = 1;
	int state = 0;
	int K = 1;
	
	while (K < 10) {
		int choice = __VERIFIER_nondet_int();
		if (choice) {
			state = state + 1;
			if (state > 3) {
				state = 0;
				counter = counter + 1;
			}
			int looped = state == 0;
			if (looped && counter <= 0) // A (looped -> counter > 0)
				goto ERROR;
		} else {
			if (counter > 0)
				counter = counter - 1;
			if (counter <= -1) goto ERROR;
		}
		
		K = K + 1;
	}
	return 0;
	ERROR:
	return -1;
}