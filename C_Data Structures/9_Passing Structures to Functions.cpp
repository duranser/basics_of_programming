#include <stdio.h>

typedef struct{
int x;
int y;
}POINT;

void display(int, int);    // Passing individual members
void display2(POINT);      // Passing entire structure
void display3(POINT *);    // Passing with pointers

int main(){
	POINT p1 = {2, 3};
	display(p1.x, p1.y);
	display2(p1);
	display3(&p1);
	
	return 0;
}
void display(int a, int b){
	printf("The coordinates of the point are: %d %d\n", a, b);
}

void display2(POINT p){
	printf("The coordinates of the point are: %d %d\n", p.x, p.y);
}

void display3(POINT *p){
	printf("The coordinates of the point are: %d %d", p->x, p->y);
}
