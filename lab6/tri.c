#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n, m, a, b, i;
    scanf("%d", &n);
    scanf("%d", &m);
    int *red = malloc(sizeof(int) * (n + 1));

    while(m--)
    {
        scanf("%d%d", &a, &b);
        ++red[a];
        ++red[b];
    }
    for (m = 0, i = 1; i <= n; ++i)
        m += red[i] * (n - 1 - red[i]);
    printf("%d", n * (n - 1) * (n - 2)/6 - m/2);

    return 0;
}

