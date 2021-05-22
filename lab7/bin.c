#include <stdlib.h>
#include <stdio.h>

int sub_function(char* arr, int index, int k, int *cur_k, int n, int last);

int main(void){
    int n, k;
    scanf("%d%d", &n, &k);
    int placeholder = 0;
    int * index = &placeholder;
    char * array = malloc(n * sizeof(char));

    int solution = sub_function(array, 0, k, index, n, 0);
    if (!solution)
        printf("-1");

    free(array);
    return 0;
}

int sub_function(char* arr, int index, int k, int *cur_k, int n, int last)
{
    if(index == n)
    {
        (*cur_k)++;
        if (*cur_k == k)
        {
            printf("%s", arr);
            return 1;
        }
        return 0;
    }
    arr[index] = '0';
    int solution = sub_function(arr, index + 1, k, cur_k, n, 0);

    if (last == 0)
    {
        arr[index] = '1';
        return sub_function(arr, index + 1, k, cur_k, n, 1) | solution;
    }

    return solution;
}
