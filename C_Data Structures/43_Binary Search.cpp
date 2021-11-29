#include <stdio.h>

#define SIZE 10


void selection_sort(int arr[], int n); 

int main() {
	int arr[SIZE];
	int num, n;
	int beg, end, mid;
	int found=0;
	
	printf("\nEnter the number of elements in the array: ");
	scanf("%d", &n);
	
	printf("\nEnter the elements: ");
	for(int i=0;i<n;i++){
		scanf("%d", &arr[i]);
	}
	
	selection_sort(arr, n); 
	
	printf("\n\nEnter the number that has to be searched: ");
	scanf("%d", &num);
	
	// Binary Search O(log2 n)    
	beg = 0;
	end = n-1;
	while(beg <= end){
		mid = (beg + end)/2;
		if (arr[mid] == num){
			printf("\n%d is present in the array at position %d", num, mid + 1);
			found = 1;
			break;
		}
		else if (arr[mid] > num)
			end = mid-1;
		else
			beg = mid+1;
	}
	
	if (beg > end && found == 0)
		printf("\n %d does not exist in the array", num);
		
	return 0;
}


void selection_sort(int arr[],int n){   // O(n^2)   Bubble Sort'la ayný
	int i, j, temp, min_index;

   for (i = 0; i < n-1; i++) {
   	   min_index = i;
       for (j = i+1; j < n; j++){
           if (arr[j] < arr[min_index])
           		min_index = j;
           }
    	temp = arr[min_index];
    	arr[min_index] = arr[i];
    	arr[i] = temp;
    }
}
