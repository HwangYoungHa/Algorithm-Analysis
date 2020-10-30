#include <cstdio>

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
	return;
}

void maxHeapify(int a[], int i, int heapsize){
	int l = i * 2; // left
	int r = i * 2 + 1; // right
	int largest = i;
	
	if (l < heapsize && a[l] > a[i])
		largest = l;
	if(r < heapsize && a[r] > a[largest])
		largest = r;
	
	if(largest != i){
		swap(&a[i], &a[largest]);
		maxHeapify(a, largest, heapsize);
	}
}

void buildHeap(int arr[], int size) {
    int i,j;
    for (i = size / 2 - 1; i >= 0; i--) {
        maxHeapify(arr, i, size);
    }
}

void heapsort(int a[], int size){
	buildHeap(a, size);
	for(int i=size-1; i>=0; i--){
		swap(&a[0], &a[i]);
		maxHeapify(a, 0, i);
	}
}

int main(){
	int arr[6] = {9, 7, 0, 6, 1, 8};
	heapsort(arr, 6);
	for(int i=0; i<6; i++)
		printf("%d ", arr[i]);
	return 0;
}
