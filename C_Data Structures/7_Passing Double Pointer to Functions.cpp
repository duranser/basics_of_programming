#include <stdio.h>
#include <stdlib.h>

void allocate(int **p){
	*p = (int *)malloc(sizeof(int));
}

void allocate2(int *p){
	p = (int *)malloc(sizeof(int));
}

int main(){
	int *x = NULL;
	
	allocate2(x);
	
	printf("%p", x);
	
	allocate(&x);
	
	printf("\n%p",x);
	
}
