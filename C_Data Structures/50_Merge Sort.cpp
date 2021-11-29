#include <stdio.h>

#define size 100

// O(nlog n)
void merge(int arr[], int beg, int mid, int end){
	int i = beg;
	int j = mid+1; 
	int index = beg; 
	int temp[size];
	int k;
	
	while( (i<=mid) && (j<=end) ){
		if(arr[i] < arr[j]){
			temp[index] = arr[i];
			i++;
		}
		else{
			temp[index] = arr[j];
			j++;
		}
	index++;
	}
	
	if(i > mid){
		while(j <= end){
			temp[index] = arr[j];
			j++;
			index++;
		}
	}
	else{
		while(i <= mid){
			temp[index] = arr[i];
			i++;
			index++;
		}
	}
	
	for(k=beg;k<index;k++)
		arr[k] = temp[k];
}

void merge_sort(int arr[],int beg, int end){
	int mid;
	if(beg < end){
		mid = (beg + end) / 2;
		merge_sort(arr, beg, mid);
		merge_sort(arr, mid+1, end);
		
		merge(arr, beg, mid, end);
	}
}


int main(){
	int arr[size], i, n;
	printf("\nEnter the number of elements in the array : ");
	scanf("%d", &n);
	printf("\nEnter the elements of the array: ");

	for(i=0;i<n;i++){
		scanf("%d", &arr[i]);
	}
	
	merge_sort(arr, 0, n-1);
	printf("\nThe sorted array is: \n");
	for(i=0;i<n;i++)
		printf(" %d\t", arr[i]);

}


