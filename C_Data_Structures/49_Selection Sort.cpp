#include <stdio.h>
  
  
void swap(int *x, int *y){ 
    int temp = *x; 
    *x = *y; 
    *y = temp; 
} 

// O(n^2)
void selectionSort(int arr[], int n){ 
   int i, j, min_index;

   for (i = 0; i < n-1; i++) {
   	   min_index = i;
       for (j = i+1; j < n; j++){
           if (arr[j] < arr[min_index])
           		min_index = j;
           }
    
	    swap(&arr[min_index], &arr[i]); 
    }
}

int main() { 
    int arr[] = {64, 34, 25, 12, 22, 11, 90, 5}; 
    int n = 8;
	 
    selectionSort(arr, n); 
    
    printf("Sorted array: \n"); 
    for(int i=0; i<n; i++)
    	printf("%d ",arr[i]);
    	
    return 0; 
} 
