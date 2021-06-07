#include <stdio.h>
#include <string.h>

int check_if_zero(int *num, int len);
int mod(int number[], int len);
void increment(int *array, int len);
int div_by_2(int *number, int len);
int atm(int *result, int *number, int len, int m);

int main(void)
{
    char tab[34];
    scanf("%s", tab);

    int len = strlen(tab);
    int num1[34];
    int num2[34];
    for (int i = 0; i < len;i++)
    {
        num1[i] = tab[i] - '0';
        num2[i] = tab[i] - '0';
    }

    int result_1[100] = {0};
    int result_2[100] = {0};
    int cond_met_1 = atm(result_1, num1, len, 1);
    int cond_met_2 = atm(result_2, num2, len, 0);


    if (cond_met_1 == 1)
    {
        for (int j = 0; j < 100 ; j++)
            if (result_1[j] == 1)
                printf("%d ", j);
    }
    else
        printf("NO");

    printf("\n");

    if (cond_met_2 == 1)
    {
        for (int j = 0; j < 100 ; j++)
            if (result_2[j] == 1)
                printf("%d ", j);
    }
    else
        printf("NO");
}

int atm(int *result, int *number, int len, int m)
{
    int i = 0;

    while (i < 100 && check_if_zero(number, len) == 0)
    {
        result[i] = mod(number, len);
        if (i % 2 == m && result[i] == 1)
            increment(number, len);
        div_by_2(number, len);
        i++;
    }

    if (check_if_zero(number, len) == 0)
        return 0;
    else
        return 1;
}

int check_if_zero(int *num, int len)
{
    for (int i = 0; i < len; i++)
        if (num[i] != 0)
            return 0;

    return 1;
}

int mod(int number[], int len)
{
    if (number[len - 1] % 2 == 1)
        return 1;
    else
        return 0;
}

void increment(int *number, int len)
{
    int i = len - 1;
    int remainder = 1;

    while (i >= 0 && remainder == 1)
    {
        number[i] += 1;
        number[i] = number[i] % 10;
        if (number[i] != 0)
            remainder = 0;
    }
}

int div_by_2(int *number, int len)
{
    int next_remainder;
    int remainder = 0;

    for (int i = 0; i < len; i++)
    {
        next_remainder = (number[i] + remainder * 10) % 2;
        number[i] = (number[i] + remainder * 10) / 2;
        remainder = next_remainder;
    }

    return remainder;
}

