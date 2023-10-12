#include <stdio.h>

int mut_int(int *n);

int main(void) {
	// store an integer on the stack
	int n = 0;
	// get addr of int
	int *ptr_n = &n;
	// write int to stdout
	printf("n = %d\n", n);
	// mutate int outside of main
	mut_int(ptr_n);
	// display change
	printf("n = %d\n", n);
	// return success on exit
	return 0;	
}

int mut_int(int *n) {
	*n = 255;
}
