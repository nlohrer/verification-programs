extern int __VERIFIER_nondet_int(void);

void main() {
	int counter = 0;
	int state = 0;
	int K = 1;
	int current;
	while (K < 10) {
		current = __VERIFIER_nondet_int();
		if (current) {
			state = state + 1;
			if (state > 3) {
				state = 0;
				counter = counter + 1;
			}
		} else {
			if (counter > 0)
				counter = counter - 1;
		}
		K = K + 1;
	}
	return 0;
	ERROR:
	return -1;
}