#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n;
    scanf("%d", &n);
    int array[200][200];
    int *x1_pos = malloc(n * sizeof(int));
    int *x2_pos = malloc(n * sizeof(int));
    int *y1_pos = malloc(n * sizeof(int));
    int *y2_pos = malloc(n * sizeof(int));
    for (int i = 0; i < 200; i++)
    {
        for (int j = 0; j < 200; j++)
            array[i][j] = 0;
    }
    for (int i = 0; i < n; i++)
        scanf("%d%d%d%d",&x1_pos[i], &y1_pos[i], &x2_pos[i], &y2_pos[i]);

    for (int i = 0; i < n; i++)
    {
        int x = x1_pos[i] + 100;
        int y = y1_pos[i] + 100;
        int ds_x = abs(x1_pos[i] - x2_pos[i]);
        int ds_y = abs(y1_pos[i] - y2_pos[i]);

        for (int k = 0; k < ds_y; k++)
        {
            int tmp = x;
            for (int m = 0; m < ds_x; m++)
            {
                if (array[y][tmp] == 0)
                    array[y][tmp] = 1;
                else
                    array[y][tmp] = 0;
                tmp++;
            }
            y++;
        }
    }

    // Count and then print a number of black squares in matrix.
    int counter = 0;
    for (int i = 0; i < 200; i++)
    {
        for (int j = 0; j < 200; j++)
        {
            if (array[i][j] == 1)
                counter++;
        }
    }
    printf("%d", counter);

    free(x1_pos);
    free(x2_pos);
    free(y1_pos);
    free(y2_pos);
    return 0;
}
