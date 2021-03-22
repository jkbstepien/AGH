#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

int main(void){
	int n;
	int sum_left, sum_right = 0;
	scanf("%d", &n);
	int arr[MAX];
	
    for(int i=0; i<n; i++){
		scanf("%d", &arr[i]);
	}
    for(int i=1; i<n; i++){
        sum_right += arr[i];
    }

    int j = 0;
    while(j<n){
        if(sum_left == sum_right){
            printf("%d", j);
            return 0;
        }
        j += 1;
        sum_left += arr[j-1];
        sum_right -= arr[j];
    }
}
