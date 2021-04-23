#include <stdio.h>
#include <stdlib.h>

int scan_row(int *arr, int n, int y, int i, int j);
int calc_plot_area(int i, int k, int j, int m);

int main(void){
    int n;
    scanf("%d", &n);
    int *arr = malloc(n * n * sizeof(int));
    for(int i = 0; i < n * n; i++) scanf("%d", &arr[i]);

    int plot_max = 0;
    int curr_plot_area = 0;
    // check for every rectangle
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            for(int k = 0; k < n; k++){
                for(int m = k; m < n; m++){
                    if(scan_row(arr, n, m, i, j) != 1){
                        k = m;
                        break;
                    }
                    curr_plot_area = calc_plot_area(i, k, j, m);
                    if(curr_plot_area > plot_max) plot_max = curr_plot_area;
                }
            }
        }
    }
    printf("%d", plot_max);

    free(arr);
    return 0;
}

int scan_row(int *arr, int n, int y, int i, int j){
    if(j < i){
        int tmp = j;
        j = i;
        i = tmp;
    }
    for(int x = i; x <= j; x++){
        if(arr[y * n + x] == 1) return 0;
    }

    return 1;
}

int calc_plot_area(int i, int k, int j, int m){
    int a = abs(j - i) + 1;
    int b = abs(m - k) + 1;
    int area = a * b;
    return area;
}
