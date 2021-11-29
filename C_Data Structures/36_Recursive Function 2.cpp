#include <stdio.h>

int max = 4;
int i = -1;

void f(int x[]){
	int val;
	++i;
	printf("\nEnter value: ");
	if( i != 4){
		scanf("%d",&val);
		*x = val;
		f(++x);
	}
	else
		return;
}


int main(){
	int y[4];
	f(y);
	
	printf("\n%d",*y);
	printf("\n%d",*(y+1));
	printf("\n%d",*(y+2));
	printf("\n%d",*(y+3));
}
