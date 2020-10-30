#include <cstdio>

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
	return;
}

int partition(int a[], int p, int r){
	int j=p-1;
	int pivot = a[r];
	for(int i=p; i<r; i++){
		if(a[i] <= pivot){
			j++;
			swap(&a[i], &a[j]);
		}
	}
	swap(&a[j+1], &a[r]);
	return j+1;
}

void quicksort(int a[], int p, int r){
	if(p < r){
		int q = partition(a, p, r);
		quicksort(a, p, q-1);
		quicksort(a, q+1, r);	
	}
}

int main(){
	int n;
	scanf("%d", &n);
	int arr[n];
	for(int i=0; i<n; i++)
		scanf("%d", &arr[i]);
		
	quicksort(arr, 0, n-1);
	
	for(int i=0; i<n; i++)
		printf("%d ", arr[i]);
	return 0;
}
