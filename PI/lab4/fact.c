//
// Created by jstepien on 03.04.2021.
//
#include <stdio.h>
#define MAX 1000

int multiply(int x, int res[], int res_size);
void fact(int num);

int main(void){
    int n;
    scanf("%d", &n);

    fact(n);
    return 0;
}

int multiply(int x, int res[], int res_size){
    int remainder = 0;

    for(int i = 0; i < res_size; i++){
        int tmp = res[i] * x + remainder;
        res[i] = tmp % 10;
        remainder = tmp / 10;
    }
    while (remainder){
        res[res_size] = remainder % 10;
        remainder = remainder / 10;
        res_size++;
    }
    return res_size;
}

void fact(int num){
    int res[MAX];
    res[0] = 1;
    int res_size = 1;

    for (int x = 2; x <= num; x++) res_size = multiply(x, res, res_size);
    for (int i=res_size-1; i>=0; i--) printf("%d", res[i]);
}