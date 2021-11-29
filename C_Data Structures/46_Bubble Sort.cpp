#include <stdio.h> 
  
  
void swap(int *x, int *y){ 
    int temp = *x; 
    *x = *y; 
    *y = temp; 
} 

// O(n^2)
void bubbleSort(int arr[], int n){ 
   int i, j; 
   for (i = 0; i < n-1; i++)         
       for (j = 0; j < n-i-1; j++)  
           if (arr[j] > arr[j+1]) 
              swap(&arr[j], &arr[j+1]); 
}

int main() { 
    int arr[] = {64, 34, 25, 12, 22, 11, 90}; 
    int n = 7;
	 
    bubbleSort(arr, n); 
    
    printf("Sorted array: \n"); 
    for(int i=0; i<n; i++)
    	printf("%d ",arr[i]);
    	
    return 0; 
} 
