#include <stdio.h>

int is_prime(int num);
int search_one_quadratic(int num);

int main(void){
    int l, u, k;
    int current_num = 0;
    scanf("%d %d %d", &l, &u, &k);

    for(; k>0 && l<=u; l++){
        if(is_prime(l)){
            if (search_one_quadratic(l)){
                current_num = l;
                k--;
            }
        }
    }
    if(k == 0) printf("%d", current_num);
    else printf("-1");
}

int is_prime(int num){
    if(num <= 1) return 0;
    if(num == 2 || num == 3) return 1;
    if(num%2 == 0 || num%3 == 0) return 0;
    for(int i=5; i*i<=num; i+=6){
        if(num%i == 0 || num%(i+2) == 0) return 0;
    }
    return 1;
}

int search_one_quadratic(int num){
    int number = num;
    int tmp = 0;

    while(number > 0){
        tmp += (number % 10) * (number % 10);
        number /= 10;
    }

    if (tmp == 4) return 0;
    else if (tmp > 1) return search_one_quadratic(tmp);
    else return 1;
}
