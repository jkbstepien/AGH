/*
 * Task "1. Last Digit" Lab8
 *
 * To solve this task first we need to calculate length of given number 'S'.
 * Then create second number 'x' as long as 'S' and consisting only of digits '1'.
 * Next step is to create our result array to print answer at the end.
 * Answer can not be longer than 'len'.
 * On each iteration of a loop we try to subtract x from S as many times as we can.
 * If it is possible, increment by 1 occurrence in result array on index j.
 * If there are more than 9 occurrences it means that we can not construct valid answer.
 */

#include <stdio.h>
#include <stdlib.h>

int get_length(long long int num);

int main(void)
{
    long long int S;
    scanf("%lld", &S);
    long long int len = get_length(S);

    int i = 1;
    long long int x = 1;
    while (i < len)
    {
        x *= 10;
        ++x;
        ++i;
    }

    int * result_array = malloc(len * sizeof(int));
    for(int j = 0; j < len; ++j)
    {
        while ((S - x) >= 0)
        {
            S -= x;
            result_array[j] ++;
            if (result_array[j] > 9)
            {
                printf("-1");
                free(result_array);
                return -1;
            }
        }
        x /= 10;
    }

    int start;
    if (result_array[0] == 0)
        start = 1;
    else
        start = 0;
    for (int k = start; k < len; ++k)
        printf("%d", result_array[k]);

    free(result_array);
    return 0;
}

int get_length(long long int num)
{
    int length = 0;

    while (num != 0)
    {
        num /= 10;
        ++length;
    }
    return length;
}