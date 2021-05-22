#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int is_prime(int n);

int main(void)
{
    char * str = malloc(51 * sizeof(char));
    scanf("%str", str);
    int n = strlen(str);
    int * result = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        result[i] = str[i];

    int p;
    int * current_str = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i != j)
            {
                if (i < j)
                    p = j - i;
                else
                    p = n - i + j;
                if (is_prime(p))
                {
                    int flag = 0;
                    int x = 0;
                    for (int k = 0; k < n; k++)
                    {
                        current_str[k] = str[(i + x * p) % n];
                        x++;
                    }
                    for (int l = 0; l < n; l++)
                    {
                        if (current_str[l] < result[l])
                        {
                            flag = 1;
                            break;
                        }
                        else if (current_str[l] > result[l])
                            break;
                    }
                    if (flag)
                        for (int m = 0; m < n; m++)
                            result[m] = current_str[m];
                }
            }
    for (int i = 0; i < n; i++)
        printf("%c", result[i]);
}

int is_prime(int n)
{
    if(n < 2) return 0;
    if(n == 2 || n == 3) return 1;
    if(n % 2 == 0 || n % 3 == 0) return 0;
    int i = 5;
    while(i <= sqrt(n))
    {
        if(n % i == 0) return 0;
        i += 2;
        if(n % i == 0) return 0;
        i += 4;
    }
    return 1;
}
