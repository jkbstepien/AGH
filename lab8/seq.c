#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char str[51];
    scanf("%s", str);
    int len = strlen(str);
    int n = len - 1;
    int * array = malloc(len * sizeof(int));
    array[n] = 'x';

    for (int i = n - 1; i > -1; i--)
        if (str[i] >= str[n])
        {
            array[i] = 'x';
            n = i;
        }
    for (int i = 0; i < len; i++)
        if (array[i] == 'x')
            printf("%c", str[i]);

    free(array);
    return 0;
}
