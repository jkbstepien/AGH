#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int min(int a, int b);
int op_min(int *red, int *green, int *blue, unsigned int n);

int main(void)
{
    unsigned int n;
    if(scanf("%d",&n) <= 0)
    {
        return 1;
    }


    int* red = malloc(sizeof(int)*n);
    int* green = malloc(sizeof(int)*n);
    int* blue = malloc(sizeof(int)*n);

    for (unsigned int i = 0; i < n;i++)
    {
        if(scanf("%d",&red[i]) <= 0)
        {
            return 1;
        }
    }
    for (unsigned int i = 0; i < n;i++)
    {
        if(scanf("%d",&green[i]) <= 0)
        {
            return 1;
        }
    }
    for (unsigned int i = 0; i < n;i++)
    {
        if(scanf("%d",&blue[i]) <= 0)
        {
            return 1;
        }
    }

    printf("%d", op_min(red, green, blue, n));

    free(red);
    free(blue);
    free(green);
}

int op_min(int *red, int *green, int *blue, unsigned int n)
{
    int DP[110][8];
    unsigned int i;
    unsigned int j;
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= 7; j++) {
            DP[i][j] = 1 << 30;
        }
    }

    DP[0][0] = 0;
    for (i = 0; i < n; i++){
        for (j = 0; j <= 7; j++){
            DP[i + 1][j | 1] = min(DP[i + 1][j | 1], DP[i][j] + green[i] + blue[i]);
            DP[i + 1][j | 2] = min(DP[i + 1][j | 2], DP[i][j] + red[i] + blue[i]);
            DP[i + 1][j | 4] = min(DP[i + 1][j | 4], DP[i][j] + red[i] + green[i]);
        }
    }

    j = 0;
    for (i = 0; i < n; i++){
        if (red[i]) j |= 1;
        if (green[i]) j |= 2;
        if (blue[i]) j |= 4;
    }

    if (DP[n][j] >= (1 << 30))
        DP[n][j] = -1;

    return DP[n][j];

}

int min(int a, int b)
{
    return (a < b) * a + (a >= b) * b;
}
