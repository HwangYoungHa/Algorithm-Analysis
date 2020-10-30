#include <cstdio>

void insertionSort(int a[], int len){
	for(int j=1; j<len; j++){
		int temp = a[j];
		int i = j-1;
		while(a[i] > temp && i > -1){
			a[i+1] = a[i];
			i--;
		}
		a[i+1] = temp;
	}
}

int main(){
	int n;
	scanf("%d", &n);
	int arr[n];
	for(int i=0; i<n; i++){
		scanf("%d", &arr[i]);
	}
	insertionSort(arr, n);
	for(int i=0; i<n; i++)
		printf("%d ", arr[i]);
	return 0;
}
