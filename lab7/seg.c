#include <stdio.h>
#include <stdlib.h>

int cmp(int num1, int num2);
int find_section(int **T, int n, int k, int i, int j);

int main(void)
{
    int n, k;
    scanf("%d %d", &n, &k);
    int **T = malloc(n * sizeof(int *));

    for (int i = 0; i < n; i++)
    {
        T[i] = malloc(n * sizeof(int));
        for (int j = 0; j < n; j++)
            scanf("%d", &T[i][j]);
    }

    int current_section;
    int sect_max = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            current_section = find_section(T, n, k, i, j);
            sect_max = cmp(current_section, sect_max);
        }
    printf("%d", sect_max);

    for (int i = 0; i < n; i++)
        free(T[i]);
    free(T);

    return 0;
}

int cmp(int num1, int num2)
{
    if (num1 > num2)
        return num1;
    return num2;
}

int find_section(int **T, int n, int k, int i, int j)
{
    int sect_max = 0;

    // right
    int sum = 0;
    for (int m = 0; m<k; m++) sum += T[i][(j + m + n) % n];
    sect_max = cmp(sum, sect_max);

    // bottom right
    sum = 0;
    for (int m = 0; m<k; m++) sum += T[(i + m + n) % n][(j + m + n) % n];
    sect_max = cmp(sum, sect_max);

    // bottom
    sum = 0;
    for (int m = 0; m<k; m++) sum += T[(i + m + n) % n][j];
    sect_max = cmp(sum, sect_max);

    // bottom left
    sum = 0;
    for (int m = 0; m<k; m++) sum += T[(i - m + 2 * n) % n][(j - m + 2 * n) % n];
    sect_max = cmp(sum, sect_max);

    // left
    sum = 0;
    for (int m = 0; m<k; m++) sum += T[i][(j - m + n) % n];
    sect_max = cmp(sum, sect_max);

    // top
    sum = 0;
    for (int m = 0; m<k; m++) sum += T[(i - m + n) % n][j];
    sect_max = cmp(sum, sect_max);

    // top left
    sum = 0;
    for (int m = 0; m<k; m++) sum += T[(j - m + n) % n][(j - m + n) % n];
    sect_max = cmp(sum, sect_max);

    // top right
    sum = 0;
    for (int m = 0; m<k; m++) sum += T[(i - m + n) % n][(j + m + n) % n];
    sect_max = cmp(sum, sect_max);

    return sect_max;
}
