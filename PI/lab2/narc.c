//
// Created by jstepien on 18.03.2021.
//
#include <stdio.h>
#include <malloc.h>
#include <math.h>


char* convert_num_to_base(int num, int base, int size){
    int i;
    char arr[] = "0123456789ABCDEF";
    char* result = malloc(sizeof(char)*size);
    i = size;
    while(num >= 1){
        i--;
        result[i] = arr[num % base];
        num /= base;
    }
    return result;
}

int check_if_narc(int num, int base, int size){
    int res = 0;
    while(num >= 1){
        res += round(pow((num % base), size));
        num /= base;
    }
    return res;
}

int main(void){
    int conditions_met = 0;
    int amount, base;
    int res, low_val, high_val;
    char* arr;
    scanf("%d%d", &amount, &base);
    low_val = round(pow(base, amount - 1));
    high_val = round((pow(base, amount) - 1));

    while(low_val <= high_val){
        res = check_if_narc(low_val, base, amount);
        if(res == low_val){
            conditions_met = 1;
            arr = convert_num_to_base(low_val, base, amount);
            printf("%s ", arr);
            free(arr);
        }
        low_val++;
    }
    if(conditions_met == 0) printf("NO");
    return 0;
}
