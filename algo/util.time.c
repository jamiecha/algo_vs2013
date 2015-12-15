#include <stdio.h>
#include <time.h>

double now(void){
	time_t t;
	t = clock();
	return (double)t;
}


double took(double a, double b){
	return (double)((b - a) / CLOCKS_PER_SEC);
}
