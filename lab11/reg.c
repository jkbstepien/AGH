#include <stdio.h>

int pow_of_two(int num);

int main(void)
{
    long s, t;
    scanf("%ld %ld", &s, &t);
    long copy_t = t;

    if (t == 1)
    {
        if (s == 1)
        {
            return 0;
        }
        else
        {
            printf("/");
            return 0;
        }
    }

    int num_of2 = 0;
    int number_of_2 = 0;
    while (copy_t % s == 0)
    {
        num_of2 ++;
        copy_t /= s;
    }
    while (copy_t % 2 == 0)
    {
        number_of_2 ++;
        copy_t /= 2;
    }

    char res[100];
    int idx = 0;
    int temp, i;

    if (num_of2 == 0 && s != 1)
    {
        res[idx] = '/';
        res[idx + 1] = '+';
        idx += 2;
        num_of2 = number_of_2;
        number_of_2 = 0;
        s = 2;
    }

    if (copy_t > 1)
    {
        printf("NO\n");
        return 0;
    }
    if (num_of2 != 0 && num_of2 != 1 && pow_of_two(num_of2) == 0)
    {
        if (s == 2)
        {
            while (pow_of_two(num_of2) == 0)
            {
                num_of2 --;
                number_of_2 ++;
            }
        }
        else
        {
            printf("NO\n");
            return 0;
        }
    }

    while (num_of2 > 1)
    {
        temp = number_of_2 / num_of2;
        i = 0;
        while (i < temp)
        {
            res[idx] = '+';
            idx ++;
            i ++;
        }
        number_of_2 -= num_of2 * temp;
        res[idx] = '*';
        idx ++;
        num_of2 /= 2;
    }
    while (number_of_2 > 0)
    {
        res[idx] = '+';
        idx ++;
        number_of_2 --;
    }
    for (int j=0; j < idx; j++)
    {
        printf("%c", res[j]);
    }
}

int pow_of_two(int num)
{
    while (num % 2 == 0)
    {
        num /= 2;
    }
    if (num > 1) return 0;
    return 1;
}