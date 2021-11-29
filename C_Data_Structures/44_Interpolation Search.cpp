#include <stdio.h>

#define MAX 20

void selection_sort(int arr[], int n); 

int interpolation_search(int a[], int n, int val){
	int low = 0;
	int high = n-1;
	int mid;
	while(low <= high){
		mid = low + (high - low)*((val - a[low]) / (a[high] - a[low]));
		if(val == a[mid])
			return mid;
		if(val < a[mid])
			high = mid - 1;
		else
			low = mid + 1;
	}
	return -1;
}

int main(){
	int arr[MAX];
	int n, val;
	
	printf("\nEnter the number of elements in the array : ");
	scanf("%d", &n);
	
	printf("\nEnter the elements : ");
	for(int i = 0; i <n; i++)
		scanf("%d", &arr[i]);
	
	selection_sort(arr, n);
	
	printf("\nEnter the value to be searched : ");
	scanf("%d", &val);

	int index = interpolation_search(arr, n, val);
	
	if(index == -1)
		printf("\n %d is not found in the array", val);
	else
		printf("\n %d is found at position %d", val, index);
	
return 0;
}


void selection_sort(int arr[],int n){   // O(n^2)   Bubble Sort'la ayný
	int k, pos, temp, small;
	for(k=0; k<n; k++){
		pos = k;
		small = arr[k];
		for(int i= k+1; i<n; i++){
			if(arr[i]< small){
				small = arr[i];
				pos = i;
			}
		}
		temp = arr[k];
		arr[k] = arr[pos];
		arr[pos] = temp;
	}
}
