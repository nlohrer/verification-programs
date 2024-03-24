int main() {
	int state = 0;
	int counter = 0;
	int live = 0;
	int found;
	int finished = 0;
	
	while (1) {
		found = state == -1;
		if (!(!finished || live)) goto ERROR;
		if (state == 3) {
			state = 0;
		} else {
			state = state + 1;
		}
		
		if (counter < 5) {
			counter = counter + 1;
		}
		
		live = live || found;
		
		finished = counter == 5;
	}
	ERROR:
	return (-1);
}