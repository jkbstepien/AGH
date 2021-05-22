#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char array_1[] = {'M', 'D', 'C', 'L', 'X', 'V', 'I'};
int array_2[] = {1000, 500, 100, 50, 10, 5, 1};
char * array_3[] = {"CM", "CD", "XC", "XL", "IX", "IV", "I"};
int array_4[] = {900, 400, 90, 40, 9, 4, 1};

int change_base_to_10(char * num);
void print_roman_sum(int n);

int main(void)
{
    // Reserve 14 places for each number because it's
    // length of the longest roman numeral.
    char *number1 = malloc(sizeof(char) * 14);
    char *number2 = malloc(sizeof(char) * 14);
    scanf("%s%s", number1, number2);
    int sum_in_10 = change_base_to_10(number1)
                    + change_base_to_10(number2);
    print_roman_sum(sum_in_10);

    free(number1);
    free(number2);
    return 0;
}

int change_base_to_10(char * num)
{
    unsigned int num_len = strlen(num);
    int sum = 0;
    int i = 0, j = 0;
    while (i < num_len)
    {
        if (num[i] == array_1[j])
        {
            sum += array_2[j];
            i++;
        }
        else if (i < num_len - 1
                && num[i] == array_3[j][0]
                && num[i + 1] == array_3[j][1])
        {
            sum += array_4[j];
            i += 2;
        }
        else
            j++;
    }
    return sum;
}

void print_roman_sum(int num)
{
    char *result = malloc(sizeof(char) * 14);

    int i = 0, j = 0;
    while(num > 0)
    {
        if (num >= array_2[j])
        {
            num -= array_2[j];
            result[i++] = array_1[j];
        }
        else if (num >= array_4[j])
        {
            num -= array_4[j];
            result[i++] = array_3[j][0];
            result[i++] = array_3[j][1];
        }
        else
            j++;
    }
    printf("%s", result);
    free(result);
}
