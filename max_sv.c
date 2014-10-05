#include <stdio.h>
#include <stdlib.h>


/* Outputs an inclusive range for the maximum subvector */
int* max_range(int* arr, int arr_len){
	
	/* Store output here */
	int* result;
	
	/* Trace the results obtained so far */
	int max_sum = 0;
	int curr_sum = 0;
	
	int i = 0;
	int start = 0;
	
	/* Allocate resources for result */
	result = (int*)calloc(2, sizeof(int));
	
	/* Process array */
	for(i = 0; i < arr_len; i++){
		curr_sum += arr[i];
		
		/* Update max_sum */
		if(curr_sum > max_sum){
			max_sum = curr_sum;
			result[1] = i;

			if(result[0] != start && start <= result[1]){
				result[0] = start;
			}
		} else if(max_sum == 0 && i == 0) { /* Special condition where first element is < 0 */
			max_sum = curr_sum;
		} else{}
		
		/* Once curr_sum dips below 0, reset */
		if(curr_sum < 0){
			/* Roll back to previous curr_sum */
			curr_sum -= arr[i];
			
			/* Reset curr_sum */
			curr_sum = 0;
			
			/* Keep track of new start location */
			start = i + 1;
		} else {}
	}
	
	return result;
}
