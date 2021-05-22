#include <stdio.h>

int odd_divider_max(int num);

int main(void)
{
    int N;
    scanf("%d", &N);

    int sum = 0;
    for (int i = 1; i <= N; i++)
        sum += odd_divider_max(i);
    printf("%d", sum);
}

int odd_divider_max(int num)
{
    int x = num;

    if (x == 1 || x == 2)
        return 1;
    if (x > 2 && x % 2 == 0)
        x -= 1;
    else
        return x;

    while (x - 2 > 0)
    {
        if (num % (x - 2) == 0)
            return x - 2;
        x -= 2;
    }

    return 0;
}
