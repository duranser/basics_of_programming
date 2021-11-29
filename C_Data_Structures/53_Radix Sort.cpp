#include <stdio.h>

#define size 10

int largest(int arr[], int n){
	int large = arr[0];
	for(int i=1; i<n; i++){
		if(arr[i]>large)
			large = arr[i];
	}
	return large;
}

// o(n)
void radixSort(int arr[], int n){
	int bucket [10][size];
	int bucket_count[10];
	int i, j, k, remainder, NOP=0, divisor=1, large, pass;
	large = largest(arr, n);
	
	while(large>0){
		NOP++;    // Number of digits
		large/=size;
	}
	for(pass=0; pass<NOP; pass++){
		for(i=0; i<size; i++)
			bucket_count[i] = 0;
		for(i=0; i<n; i++){
			remainder = (arr[i]/divisor)%size;
			bucket[remainder][ bucket_count[remainder] ] = arr[i];
			bucket_count[remainder] ++;  // ayný basamak deðeri için
		}
		i=0;
		for(k=0; k<10; k++){
			for(j=0; j<bucket_count[k]; j++){
				arr[i] = bucket[k][j];
				i++;
			}
		}
		divisor *= size;
	}
}


int main(){
	int n = 10;
	int arr[n] = {100, 203, 506, 980, 774, 885, 691, 999, 192, 333};
	
	radixSort(arr, n);
	
	for(int i=0; i<n; i++)
		printf("%d  ", arr[i]);
	
	return 0;
}
