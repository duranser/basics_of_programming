#include <stdio.h>

// O(n^2)
void insertionSort(int arr[], int n){
	int i, j, val;
	for(i=1; i<n; i++){
		val = arr[i];
		j = i-1;
		
		while(j>=0 && arr[j] > val){
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = val;
	}
}

int main(){
	int arr[8] = {12, 11, 15, 5, 6, 24, 1, 3};
	int n = 8;
	
	insertionSort(arr, n);
	
	for(int i = 0; i<n; i++)
		printf("%d ", arr[i]);
	
}
