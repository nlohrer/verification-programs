int main() {
	int state = 0;
	int loop = 0;
	int live = 0;
	int save = 1;
	int saved = 0;
	int found = 0;
	int looped = 0;
	
	int state_n, loop_n, live_n, saved_n, found_n, looped_n;
	
	while (1) {
		if (looped && !live) goto ERROR;
		found_n = state == -1;
		
		if (state == 3) {
			state_n = 0;
		} else {
			state_n = state + 1;
		}
		
		saved_n = saved || save;
		
		if (!saved && save) {
			loop_n = state;
		} else {
			loop_n = loop;
		}
		
		live_n = live || found;
		
		looped_n = saved && state == loop;
		
		state = state_n;
		loop = loop_n;
		live = live_n;
		saved = saved_n;
		found = found_n;
		looped = looped_n;
	}
	ERROR:
	return (-1);
}