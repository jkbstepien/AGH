//
// Created by jstepien on 22.03.2021.
//
#include <stdio.h>

int max_value(int arr[],int n){
    int index_max = 0;
    for(int i= 1; i<n; i++){
        if(arr[i] > arr[index_max]){
            index_max = i;
        }
    }
    if(arr[index_max] != 1){
        arr[index_max] /= 2;
        return index_max;
    }
    else return -1;
}

int sum_of_array(int arr[], int n){
    int sum = 0;

    for(int i=0; i<n; i++){
        sum += arr[i];
    }
    return sum;
}

int main(void){
    int n, k;
    int i=0, j=1;
    int sum;
    scanf("%d %d", &n, &k);
    int arr[n];
    for(i; i<n; i++){
        scanf("%d", &arr[i]);
    }

    for(j; j<=k; j++){
        if(arr[max_value(arr, n)] == -1){
            //printf("%d", n);
            return 0;
        }
    }
    sum = sum_of_array(arr, n);
    printf("%d", sum);
}
