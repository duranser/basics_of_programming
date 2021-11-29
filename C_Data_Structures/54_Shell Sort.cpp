#include <stdio.h>


void shellSort(int arr[], int n){
	int flag = 1;
	int gap = n;
	int i, temp;
	while( gap >1 ){
		gap = (gap + 1) / 2;
		for(i=0; i< n-gap; i++){
			if(arr[i+gap] < arr[i]){
				temp = arr[i+gap];     // swap
				arr[i+gap] = arr[i];
				arr[i] = temp;
			}
		}
	}
}

int main(){
	int i, n;
	int arr[n];
	
	printf("\nEnter the number of elements in the array: ");
	scanf("%d", &n);
	
	printf("\nEnter %d numbers: ",n); // n was added
	for(i=0; i<n; i++)
		scanf("%d", &arr[i]);
		
	shellSort(arr, n);
	
	for(i=0; i<n; i++)
		printf("%d ",arr[i]);
}
