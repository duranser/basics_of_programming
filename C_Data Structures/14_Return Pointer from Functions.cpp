#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *getRandom();

int main(){
	int *p, i;	
	p = getRandom();
	
	printf("\n\n");
	
	for(i = 0; i<10; i++){
		printf("*(p + [%d]) : %d\n",i ,*(p+i) );
	}
}

int *getRandom(){
	static int r[10];
	int i;
	
	srand( time(NULL));
	
	for(i=0; i<10; i++){
		r[i] = rand()%10;
		printf("%d ", r[i]);
	}
	
	return r;
}
