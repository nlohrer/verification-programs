extern int __VERIFIER_nondet_int(void);

int main() {
	int x = 0;
	int K = 1;
	int l2 = 3, l3 = 5;
	int ls2, ls3;
	while (K < 2) {
		ls2 = __VERIFIER_nondet_int();
		ls3 = __VERIFIER_nondet_int();
		if ((l2 == 3 || l2 == 4) && ls2 != l2) {
			if (l2 == 3) l2 = 4;
			if (l2 == 4 && ls2 != l2) {
				x = x + 1;
				l2 = -1;
			}
		} else l2 = -1;
		
		if ((l3 == 5 || l3 == 6) && ls3 != l3) {
			while ((x > 0 || l3 == 6) && ls3 != l3) {
				if (l3 == 5) l3 = 6;
				if (l3 == 6 && ls3 != l3) {
					x = x - 1;
					l3 = 5;
				}
			}
			if (ls3 != l3) l3 = 7;
		}
		if (l3 == 7 && ls3 != l3) {
			x = x - 2;
			l3 = -1;
		}
		
		
		if (l3 == -1 && l2 == -1) goto ERROR;
		K = K + 1;
	}
	
	if (l2 == 3 || l2 == 4) {
		if (x > 0 && l2 == 3 || l2 == 4) {
			if (l2 == 3) l2 = 4;
			if (l2 == 4) {
				x = x + 1;
				l2 = -1;
			}
		} else l2 = -1;
	}
	
	if (l3 == 5 || 6 <= l3 && l3 <= 6) {
		while (x > 0 || 6 <= l3 && l3 <= 6) {
			if (l3 == 5) l3 = 6;
			if (l3 == 6) {
				x = x - 1;
				l3 = 5;
			}
		}
		l3 = 7;
	}
	if (l3 == 7) {
		x = x - 2;
		l3 = -1;
	}
	
	if (l3 == -1 && l2 == -1) goto ERROR;
	int y = x;
	
	return 0;
	ERROR:
	return -1;	
}