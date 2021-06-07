#include <stdio.h>
#define OFFSET 50

int evaluate_end(int *array);

int main(void) {

    int array[15000];
    for (int i = 0; i < 15000; i++)
        array[i] = 0;

    int n = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int m = 0;
        scanf("%d", &m);
        m += OFFSET;
        scanf("%d", &array[m]);
    }

    int plc3 = 1;
    while (plc3)
    {
        plc3 = 0;

        for (int i = 2; i < 14997; i++)
        {
            if (array[i] >= 3)
            {
                array[i - 2] += array[i] / 3;
                array[i + 2] += array[i] / 3;
                array[i] = array[i] % 3;

                if (array[i - 2] >= 3)
                    plc3 = 1;
            }
        }
    }

    int k = -1;
    for (int i = 0; i < 14997; i++)
    {
        if (array[i] != 0)
            k = i - 1;
    }

    while (evaluate_end(array) == 0)
    {
        int initial = 0;

        if (array[k] > 0 && array[k + 1] > 0)
        {
            array[k] -= 1;
            array[k + 1] -= 1;
            array[k + 2] += 1;
            initial = 1;
            k += 2;
        }
        else if (array[k] == 2 && array[k - 1] > 0)
        {
            initial = 1;
            k -= 1;
        }
        else if (array[k] == 2 && array[k + 1] == 0)
        {
            array[k] -= 1;
            array[k - 1] += 1;
            array[k - 2] += 1;
            array[k - 1] -= 1;
            array[k] -= 1;
            array[k + 1] += 1;
            initial = 1;
            k += 1;
        }
        else if (array[k] == 3)
        {
            array[k - 2] += array[k] / 3;
            array[k + 2] += array[k] / 3;
            array[k] = array[k] % 3;
            initial = 1;
            k += 2;
        }

        int left = -1;
        int left_max = -1;
        for (int i = 0; i < 14997; i++)
        {
            if (array[i] && left_max == -1)
                left_max = i;
            if (array[i] && i < k)
                left = i;
        }

        if (k == left_max && initial == 0)
            break;
        else if (initial == 0)
            k = left;

    }

    for (int i = 0; i < 14997; i++)
    {
        if (array[i] != 0)
            printf("%d ", i - OFFSET);
    }
}

int evaluate_end(int *array)
{
    for (int i = 0; i < 14999; i++)
    {
        if (array[i] != 0 && array[i + 1] != 0)
            return 0;
        if (array[i] > 1 || array[i + 1] > 1)
            return 0;
    }

    return 1;
}
