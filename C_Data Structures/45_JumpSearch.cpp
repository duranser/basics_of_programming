#include <stdio.h>
#include <math.h>

int min(int x, int y){
	return (x < y) ? x : y;	
}

// O(sqrt(n))
int jumpSearch(int arr[], int val, int n){
	int step = sqrt(n);
	int prev = 0;
	
	while( arr[min(step, n) - 1] < val){
		prev = step;
		step += sqrt(n);
		if(prev >= n)
			return -1;
	}
	
	while(arr[prev] < val){
		prev++;
		if(arr[prev] == val)
			return prev;
		if(prev == min(step, n))
			return -1;
	}
	
	return -1;
}



int main(){
	int arr[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 
                34, 55, 89, 144, 233, 377, 610 }; 
    int x = 55; 
    int n = 16; 
      
    // Find the index of 'x' using Jump Search 
    int index = jumpSearch(arr, x, n); 
  
    // Print the index where 'x' is located 
    printf("Number %d is at index %d", x, index);

    return 0; 
}



