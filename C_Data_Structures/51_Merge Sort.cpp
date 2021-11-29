#include <stdio.h>
  
void merge(int arr[], int beg, int mid, int end){
	int i, j ,k;
	int n1 = mid - beg + 1;
	int n2 = end - mid;
	
	// Temp arrays
	int B[n1], E[n2];
	
	for(i = 0; i<n1; i++)
		B[i] = arr[beg + i];
	for(j = 0; j<n2; j++)
		E[j] = arr[mid + 1 + j];
	
	i = 0;
	j = 0;	
	k = beg;
	
	while(i<n1 && j<n2){
		if( B[i] <= E[j] ){
			arr[k] = B[i];
			i++;
		}
		else{
			arr[k] = E[j];
			j++;
		}
		k++;
	}
	
	while(i < n1){
		arr[k] = B[i];
		i++;
		k++;
	}
	
	while(j < n2){
		arr[k] = E[j];
		j++;
		k++;
	}
}

void mergeSort(int arr[], int beg, int end){
	if(beg < end){
		int mid = beg + (end-beg) / 2;
		
		mergeSort( arr, beg, mid);
		mergeSort( arr, mid+1, end);
		
		merge(arr, beg, mid, end); 
	}
}


int main(){ 
	int arr[] = {12, 11, 13, 5, 6, 7};
	int arr_size = sizeof(arr)/sizeof(arr[0]);
    
    mergeSort(arr, 0, arr_size-1);
    
    for(int i=0; i<8; i++)
    	printf("%d ", arr[i]);
    	
    return 0; 
} 
