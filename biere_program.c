int main() {
	int state = 0;
	int found;
	while (1) {
		found = state == -1;
		if (found) goto ERROR;
		if (state == 3) {
			state = 0;
		} else {
			state = state + 1;
		}
	}
	ERROR:
	return (-1);
}