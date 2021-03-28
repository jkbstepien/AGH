//
// Created by jstepien on 22.03.2021.
//
#include <stdio.h>
#include <stdlib.h>

int compare(const void * a, const void * b) {
    int *x = (int *) a;
    int *y = (int *) b;
    return *x - *y;
}

int main(void){
    int n, k;
    int counter, left, right;
    int check_conditions;
    scanf("%d %d", &n, &k);
    int* arr = (int*) calloc(n, sizeof(int));
    for(int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }

    qsort(arr, n, sizeof(int), compare);

    counter = 0;
    int j = 0;
    while(j < n){
        check_conditions = 0;
        left = j - 1;
        right = j + 1;

        if(left >= 0 && arr[left] >= arr[j] - k){
            check_conditions = 1;
        }
        while(right < n && arr[right] == arr[j]){
            right++;
        }
        if(right < n && arr[right] <= arr[j] + k){
            check_conditions = 1;
        }
        if(check_conditions == 1) counter += right - j;
        j = right;
    }
    printf("%d", counter);
    return 0;
}