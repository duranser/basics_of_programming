#include <stdio.h>

int main(){
	int *x, *y, **z, t;
	t = 2;
	y = &t;
	x = y;
	z = &y;
	
	printf("%p\n",x);   // x stores address of t
	printf("%p\n",y);   // y stores address of t
	printf("%p\n",*z);  // *z points to y (address of t)
	printf("%p\n", &y); 
	printf("%p\n", z);  // z stores address of y
	printf("%d\n",*x);
	printf("%d\n",*y);
	printf("%d\n",**z); 
	
}
