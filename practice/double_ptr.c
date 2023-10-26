#include <stdio.h>
#include <stdlib.h>

int main(void) {
    // Single pointer
    char array_of_char[12] = "Array of c\n";
	printf(array_of_char);
    // Double pointer
	
	char array_of_array[10][2] = {"A\0", "r\0", "r\0", "a\0", "y\0", " \0",
			"o\0", "f\0", " \0", "A\0"};
	for (int i = 0; i < 10; i++) {
		printf(array_of_array[i]);
	}

	return 0;

}

