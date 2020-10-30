#include <cstdio>

void swap(int *n1, int *n2){
	int temp = *n1;
	*n1 = *n2;
	*n2 = temp;
}

void bubbleSort(int a[], int len){
	for(int i=0; i<len; i++){
		for(int j=len-1; j>i; j--){
			if(a[j-1] > a[j])
				swap(&a[j-1], &a[j]);
		}
	}
}

int main(){
	int n;
	scanf("%d", &n);
	int arr[n];
	for(int i=0; i<n; i++)
		scanf("%d",&arr[i]);
		
	bubbleSort(arr, n);
	for(int i=0; i<6; i++)
		printf("%d ", arr[i]);
	return 0;
}
