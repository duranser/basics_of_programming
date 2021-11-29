#include <stdio.h>

typedef struct{
	int x,y;
	char a[20];
}POINT1;

typedef union{
	int x,y;
}POINT2;

int main(){
	POINT1 p1 = {2,3};
	// POINT2 p2 = {4,5}; is illegal
	POINT2 p2;
	p2.x=4;
	p2.y=5;
	
	printf("The coordinates of P1 are %d and %d\n", p1.x, p1.y);
	printf("The coordinates of P2 are %d and %d\n", p2.x, p2.y);
	
	p2.x = 4;
	printf("\nThe x coordinate of P2 is %d", p2.x);
	p2.y = 5;
	printf("\nThe y coordinate of P2 is %d", p2.y);
	
	return 0;
}

