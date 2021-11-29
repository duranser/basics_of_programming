#include <stdio.h>
#include <conio.h>

int main() {
	char x[2][30];
	int i;
	for( i=0; i<2; i++){
		printf("Enter a string:\n");
		fgets(x[i],30,stdin);
	}
	
	printf("%s\n",x[0]);
	printf("%s\n",x[1]);

	getch();
}
