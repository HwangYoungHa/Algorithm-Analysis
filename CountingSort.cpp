#include <cstdio>

void countingSort(int in[], int out[], int n, int k){
	int temp[k+1] = {0, };
	for(int i=0; i<n; i++){ // 개수만큼 더하기 
		temp[in[i]]+=1;
	}
	for(int i=0; i<=k; i++) {
		printf("%d의 개수 : %d\n", i, temp[i]);
	}
	printf("\n");
	for(int i=1; i<=k; i++){ // 누적 
		temp[i]+=temp[i-1];
	}
	for(int i=n-1; i>=0; i--){
		out[temp[in[i]]-1] = in[i]; // 위치 확인 주의 
		temp[in[i]]--;
	}
}

int main(){
	int n;
	scanf("%d", &n) ;
	int input[n]={0, };
	int output[n]={0, };
	int max=0;
	for(int i=0; i<n; i++)
		scanf("%d", &input[i]);
		
	for(int i=0; i<n; i++){
		if(input[i] > max)
			max = input[i];
	}
	
	countingSort(input, output, n, max);
	
	for(int i=0; i<n; i++)
		printf("%d ", output[i]);
		
	return 0;
}
