//
// Created by jstepien on 17.03.2021.
//
#include <stdio.h>
#define SIZE 100

int weight(int arr[SIZE], int n, int p){
    if(n == 0) return 1;
    if(p == sizeof(arr)) return 0;

    return weight(arr, n-arr[p], p+1) || weight(arr, n, p+1) || weight(arr, n+arr[p], p+1);
}

int main(){
    int n, w;
    int arr[SIZE];
    scanf("%d", &n);
    scanf("%d", &w);
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    int result = weight(arr, n, 0);
    if(result == 1) printf("YES");
    else printf("NO");
}
