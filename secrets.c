#include <stdio.h>
#include <stdlib.h>
#define MAX 9999

int main() {
	/* Find out from user how many people will be playing */
	int participants;
	printf("How many people will be participating? ");
	scanf("%d", &participants);
	
	/* Create holders, counters, and arrays */
	int null_count, i, temp1, temp2;
	null_count = 0;
	int give[participants], receive[participants];
	
	/* Fill arrays */
	for (i = 0; i <= participants; i++) 
		give[i] = receive[i] = i;
	
	printf("\tGiver\tReceiver\n");
	
	/* When a user gives or receives a gift, its value in the array is set to '9999'. 
	Loop checks if value is unused, returns value if it hasn't been used before. If it was 
	used, loop rerandomizes another value. */
	while (null_count <= participants) {
		temp1 = rand() % participants;
		temp2 = rand() % participants;
		if (give[temp1] == MAX && receive[temp2] == MAX) {
			temp1 = rand() % participants;
			temp2 = rand() % participants;
		}
		else if (give[temp1] == receive[temp2]) {
			temp2 = rand() % participants;
		}
		else if (give[temp1] == MAX) {
			temp1 = rand() % participants;
		}
		else if (receive[temp2] == MAX) {
			temp2 = rand() % participants;
		}
		else {
		printf("\t %d ->\t %d\n", temp1, temp2);
		give[temp1] = MAX;
		receive[temp2] = MAX;
		null_count++;
		}
	}
	return 0;
}
