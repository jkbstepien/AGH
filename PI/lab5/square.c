#include <stdio.h>
#include <stdlib.h>

int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    int *arr = malloc(sizeof(int) * n * n);
    int *res_arr = malloc(sizeof(int) * n * n);
    for(int i = 0; i<n*n;i++) scanf("%d",&arr[i]);

    int sum;
    int counter = 0;
    for(int row = 1; row < n - 1; row++){
        for(int col = 1; col < n - 1; col++){
            int curr_size = 1;
            while((row + curr_size >= n || col + curr_size >= n || row - curr_size < 0 || col - curr_size < 0) == 0){
                sum = 0;
                for(int i = row - curr_size; i <= row + curr_size; i++){
                    sum += arr[(i * n) + (col - curr_size)] + arr[(i * n) + (col + curr_size)];
                }
                for(int i = col - curr_size + 1; i <= col + curr_size - 1; i++){
                    sum += arr[((row - curr_size) * n) + i] + arr[((row + curr_size) * n) + i];
                }
                if (sum == k){
                    res_arr[counter] = row;
                    res_arr[counter + 1] = col;
                    counter += 2;
                }
                curr_size += 2;
            }
        }
    }
    printf("%d\n",counter/2);
    for (int i = 0; i < counter; i += 2){
        printf("%d %d\n", res_arr[i], res_arr[i + 1]);
    }

    free(arr);
    free(res_arr);
    return 0;
}
