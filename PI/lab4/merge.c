//
// Created by jstepien on 03.04.2021.
// PROGRAM DOES NOT MEET TASK REQUIREMENTS
//
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int compare(const void * a, const void * b) {
    int *x = (int *) a;
    int *y = (int *) b;
    return *x - *y;
}

int main(void){
    int n;
    int arr[MAX*MAX], res_arr[MAX*MAX];
    int index = 0;

    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &arr[index]);
            index++;
        }
    }
//    for(int k = 0; k < n*n; k++) printf("%d ", arr[k]);
    qsort(arr, n*n, sizeof(int), compare);

    int i = 0, p = 0;
    int right;
    while(i < n*n){
        right = i + 1;
        res_arr[p] = arr[i];
        while(right < n*n && arr[right] == arr[p]) right++;
        i = right;
        p++;
    }
//    printf("\n");
    for(int k = 0; k < n*n; k++){
        if(k < n*n && arr[k] == arr[k+1]) continue;
        else printf("%d ", arr[k]);
    }
    return 0;
}