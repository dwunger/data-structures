#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int *sortn(int array[], int len) {
	int *sorted = malloc(sizeof(int) * len);

	if (sorted == NULL) {
		puts("Unable to allocate memory!");
		return NULL;
	}
	
	// Copy array into sorted
	for (int i = 0; i < len; i++) {
		sorted[i] = array[i];
	}

	for (int i = 0; i < len; i++) {
		
		int min_idx = i;

		for (int j = i + 1; j < len; j++) {
						
			if ( array[j] < array[min_idx]) {
				
				min_idx = j;
			}
		}
		

		sorted[i] = array[min_idx];
		array[min_idx] = array[i];
	}
	return sorted;
}

int main()
{
	int rand_arr[] = { 5, 32, 22, 58, 29, 47, 19, 30, 11, 4, 7 };
	int len = sizeof(rand_arr) / sizeof(rand_arr[0]);

	printf("Length: %d\n", len);
	puts("==========UNSORTED==========");

	for (int i = 0; i < len; i++){
		printf("%d\n", rand_arr[i]);
	}

	puts("===========SORTED===========");
	
	int *sorted = sortn(rand_arr, len);

	for (int i = 0; i < len; i++) {
		printf("%d\n", sorted[i]);
	}
	
	free(sorted);

	return 0;
}
