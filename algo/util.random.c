#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generate_randint(int arr[], int size, int max){
	int i;
	srand((unsigned int)time(NULL));
	for (i = 0; i < size; i++){
		arr[i] = rand() % max;
	}
}