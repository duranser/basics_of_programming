#include <stdio.h>

void passing(int **);

int main() {
	int var;
	int *ptr;
	int **pptr;
//  int **pptr = &ptr;
	
	var=100;
	ptr=&var;
	pptr=&ptr;
	
	printf("%d\n",var);
	printf("%d\n",*ptr);
	printf("%d\n",**pptr);
	
	passing(&ptr);   // Passing pointer to double pointer
	
}

void passing(int **ptr){
	printf("%d",**ptr);
}
