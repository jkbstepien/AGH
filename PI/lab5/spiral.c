#include <stdio.h>
#include <stdlib.h>

void print_arr(int *arr, int n);

int main(void){
    int n;
    scanf("%d", &n);
    int *arr = malloc(n * n * sizeof(int));
    int x = 0;
    int y = n - 1;
    int next_num = 1;

    while(y != 0){
        int i = 0;
        // right, down, left, up
        for(i = x; i < y; i++) arr[x * n + i] = next_num++;
        for(i = x; i < y; i++) arr[i * n + y] = next_num++;
        for(i = y; i > x; i--) arr[y * n + i] = next_num++;
        for(i = y; i > x; i--) arr[i * n + x] = next_num++;
        x++;
        y--;
    }
    if (n % 2 == 1)
        arr[((n/2)*n)+(n/2)] = next_num;

    print_arr(arr, n);
    free(arr);
    return 0;
}

void print_arr(int *arr, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%d ", arr[i * n + j]);
        }
        printf("\n");
    }
}
