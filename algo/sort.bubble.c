#include <stdio.h>
#include <stdlib.h>

extern void generate_randint();

#define NMAX 100
static int arr[NMAX];

static void print_array(int a[], int sz){
	int i;
	for (i = 0; i < sz; i++){
		printf("%d ", a[i]);
	}
	printf("\n");
}

void sort_bubble(){
	int i, j, tmp;

	generate_randint(arr, NMAX, 100);

	print_array(arr, NMAX);

	for (i = NMAX - 1; i > 0; i--){
		for (j = 0; j < i; j++){
			if (arr[j] > arr[j + 1]){
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}

	print_array(arr, NMAX);
	return;
}