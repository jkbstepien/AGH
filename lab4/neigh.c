#include <stdio.h>
#include <stdlib.h>

void print_arr(int *arr, int n);
int border_cases(int n, int i, int j);
int refactor_matrix(int * arr, int n, int i, int j, int r);

int main(void){
    int n, r;
    scanf("%d %d", &n, &r);
    int *arr = malloc(n * n * sizeof(int));
    int *result_arr = malloc(n * n * sizeof(int));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) scanf("%d", &arr[i * n + j]);
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            result_arr[i * n + j] = refactor_matrix(arr, n, i, j, r);
        }
    }

    print_arr(result_arr, n);
    free(arr);
    free(result_arr);

    return 0;
}

int border_cases(int n, int i, int j){
    if((i >= 0 && j >= 0 && i < n && j < n) == 1) return 1;
    else return 0;
}

int refactor_matrix(int * arr, int n, int i, int j, int r){
    int nearby_digits = 0;
    // y is adequate to rows and x to columns of matrix
    for(int y = i - r; y <= i + r; y++){
        if(border_cases(n, y, 0) == 1) {
            for(int x = j - r; x <= j + r; x++){
                if((border_cases(n, y, x)) == 1){
                    nearby_digits += arr[y * n + x];
                }
            }
        }
    }
    return nearby_digits;
}

void print_arr(int *arr, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%d ", arr[i * n + j]);
        }
        printf("\n");
    }
}
