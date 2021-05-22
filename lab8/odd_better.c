#include <stdio.h>

int main(void)
{
    int N;
    scanf("%d",&N);
    long long int suma = 0;

    int j = 1;
    // Traverse through every possible odd divider up to N.
    for(int i = 1; i <= N; i += 2)
    {
        j = i;
        // Sum multiplies of chosen divider up to N.
        while (j <= N)
        {
            suma += i;
            j *= 2;
        }
    }
    printf("%lld", suma);
}

