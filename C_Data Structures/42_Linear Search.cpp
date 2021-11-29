#include <stdio.h>
#include <stdlib.h>

#define SIZE 20

int main() {
	int arr[SIZE]; 
	int num, n;
	int found = 0, pos = -1;
	
	printf("\nEnter the number of elements in the array : ");
	scanf("%d", &n);
	
	printf("\nEnter the elements: ");
	for(int i=0;i<n;i++){
		scanf("%d", &arr[i]);
	}
	
	printf("\nEnter the number that has to be searched : ");
	scanf("%d", &num);
	
	// Linear Search O(n)
	for(int i=0; i<n; i++){
		if(arr[i] == num){
			found = 1;
			pos = i;
			printf("\n %d is found in the array at position= %d", num, i+1);
			break;
		}
	}
	
	if (found == 0){
		printf("\n%d does not exist in the array", num);
	}
	
return 0;
}
