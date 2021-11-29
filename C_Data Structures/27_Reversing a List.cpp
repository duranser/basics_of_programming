#include <stdio.h>

int stk[10];
int top = -1;
int pop();
void push(int);

int main(){
	int val, n, i;
	int arr[10];
	
	printf("\nEnter the number of elements in the array: ");
	scanf("%d", &n);
	printf("\nEnter the elements of the array: ");
	for(i=0; i<n; i++)
		scanf("%d", &arr[i]);
	for(i=0; i<n; i++)
		push(arr[i]);
	for(i=0; i<n; i++){
		val = pop();
		arr[i] = val;
	}
	printf("\nThe reversed array is: ");
	for(i=0; i<n; i++)
		printf("\n%d", arr[i]);
}

void push(int val){
	stk[++top] = val;
}

int pop(){
	return(stk[top--]);
}

