#include <stdio.h>

void increment(int array[], int size);
int check_if_equal(const int x[], const int y[], int size);
int rec_function(int array[][2], int ipt[], int w);

int main(void)
{
    int n, m, b_exit;
    scanf("%d %d %d", &n, &m, &b_exit);

    int arr[m][2];
    for(int i = 0; i < m; i++){
        scanf("%d %d", &arr[i][0], &arr[i][1]);
    }

    char ipt[n + 1];
    char A[n + 1];
    scanf("%s", ipt);
    scanf("%s", A);

    int after_ipt[n];
    int T[n];
    int ctr = 0;
    for(int i=n; i>=0; i--)
    {
        if(ipt[i] == 49)
            after_ipt[i]=1;
        else
            after_ipt[i]=0;

        if(A[i] == 49)
            T[i]=1;
        else
            T[i]=0;
    }

    while(check_if_equal(after_ipt, T, n) == 0){
        ctr += rec_function(arr, after_ipt, b_exit - 1);
        increment(after_ipt, n);
    }

    ctr += rec_function(arr, after_ipt, b_exit - 1);
    printf("%d", ctr);

    return 0;
}

int rec_function(int array[][2], int ipt[], int w){

    int x;
    int y;

    if(array[w][0] < 0)
        x = ipt[-array[w][0] - 1];
    else
        x = rec_function(array, ipt, array[w][0] - 1);

    if(array[w][1] < 0)
        y =ipt[-array[w][1] - 1];
    else
        y = rec_function(array, ipt, array[w][1] - 1);

    return x ^ y;
}

int check_if_equal(const int x[], const int y[], int size){

    for(int i = size - 1; i >= 0; i--)
    {
        if(x[i] != y[i])
            return 0;
    }

    return 1;
}

void increment(int array[], int size){
    int j = size - 1;

    while(j >= 0)
    {
        if(array[j] == 0)
        {
            array[j]=1;
            return;
        }
        else
            array[j]=0;

        j--;
    }
}
