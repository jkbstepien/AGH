#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    int N;
    long int M;
    scanf("%d %lu", &N, &M);
    long int num;
    long int num_MAX = pow(2, N);
    long int ctr = 0;

    for (long int i = 1; i < num_MAX; i++)
        if (i % M != 0)
            for (long int j = 0; j < N; j++)
            {
                num = i ^ (1 << j);
                if (num % M == 0 && num != 0)
                {
                    ctr++;
                    break;
                }
            }
    printf("%ld", ctr);

    return 0;
}