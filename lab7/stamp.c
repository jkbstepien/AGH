#include <stdio.h>
#include <stdlib.h>

int count_covered_values(int ** T, int ** P, int highest_num, int k, int l, int n, int i, int j);

int main(void)
{
    int n, k, l;
    scanf("%d%d%d", &n, &k, &l);

    int **T = malloc(n * sizeof(int*));
    for(int i = 0; i < n; i++)
    {
        T[i] = malloc(n * sizeof(int));
        for(int j = 0; j < n; j++)
            scanf("%d", &T[i][j]);
    }

    int **P = malloc(k * sizeof(int*));
    for(int i = 0; i < k; i++)
    {
        P[i] = malloc(l * sizeof(int));
        for(int j = 0; j < l; j++){
            scanf("%d", &P[i][j]);
        }
    }

    int highest_num = count_covered_values(T, P, 0, k, l, n, 0, 0);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            int solution = count_covered_values(T, P, highest_num, k, l, n, i, j);
            if (solution > highest_num)
                highest_num = solution;
        }
    }
    printf("%d", highest_num);

    for(int i = 0; i < n; i++)
        free(T[i]);
    free(T);

    for(int i = 0; i < k; i++)
        free(P[i]);
    free(P);

    return 0;
}

int count_covered_values(int ** T, int ** P, int highest_num, int k, int l, int n, int i, int j)
{
    if (i + k > n || l + j > n)
        return highest_num;

    int sum = 0;
    for(int x = 0; x < k; x++)
    {
        for(int y = 0; y < l; y++)
        {
            if(P[x][y] == 1)
                sum += T[x + i][y + j];
        }
    }

    return sum;
}
