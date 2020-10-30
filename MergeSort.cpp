#include <cstdio>

void merge(int a[], int p, int q, int r){
	int i=p, j=q+1, k=p;
	int cnt = r-p+1;
	int temp[cnt]; // temp[r-p]할 경우 오류 
	
	while(i<=q && j<=r){
		if(a[i] < a[j])
			temp[k++] = a[i++];
		else
			temp[k++] = a[j++];
	}
	while(i<=q)
		temp[k++] = a[i++];
	while(j<=r)
		temp[k++] = a[j++];
	
	for(int cnt=p; cnt<r+1; cnt++)
		a[cnt]=temp[cnt];
}

void mergesort(int a[], int p, int r){
	int q;
	if(p < r){
		q = (p+r)/2;
		mergesort(a, p, q);
		mergesort(a, q+1, r);
		merge(a, p, q, r);
	}
}
int main(){
	int n;
	scanf("%d", &n);
	int arr[n];
	for(int i=0; i<n; i++)
		scanf("%d", &arr[i]);
	
	mergesort(arr, 0, n-1);
	for(int i=0; i<n; i++){
		printf("%d ", arr[i]);
	}
	return 0;
}
