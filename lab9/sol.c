#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n, G;
    scanf("%d %d", &n, &G);
    int * array = malloc(n * sizeof (int));
    for (int i = 0; i < n; i ++)
        scanf("%d", &array[i]);

    int tmp = 0, ctr = 0;
    int x = G;
    while (x > 0)
    {
        ctr += 1;
        x /= 2;
    }

    int max_v = ctr;
    int * result = calloc(max_v, sizeof (int));
    for (int i = 0; i < n; i++) {
        ctr = 0;
        x = array[i];
        while (x > 0) {
            if (G >> ctr & 1 && array[i] >> ctr & 1) {
                result[ctr] += 1;
            } else if (G >> ctr ^ array[i] >> ctr && array[i] >> ctr & 1) {
                array[i] = 0;
                break;
            }
            ctr += 1;
            x /= 2;
        }
        if (ctr > max_v)
            array[i] = 0;
    }

    int fq = 20, ind;
    for (int i = 0; i < max_v; i++)
    {
        if (result[i] != 0 && result[i] < fq)
        {
            fq = result[i];
            ind = i;
        }
    }
    for (int i = 0; i < n;i++)
    {
        if (array[i] != 0)
        {
            x = array[i];
            ctr = 0;
            while (x > 0 && ctr <= ind)
            {
                if (ctr == ind && array[i] >> ctr & 1)
                {
                    tmp += 1;
                    break;
                }
                x /= 2;
                ctr += 1;
            }
        }
    }
    printf("%d", tmp);
    free(array);
    free(result);

    return 0;
}