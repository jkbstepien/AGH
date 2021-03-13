#include <stdio.h>

int is_prime(int num){
	if(num <= 1) return 0;
	if(num == 2 || num == 3) return 1;
	if(num%2 == 0 || num%3 == 0) return 0;
	for(int i=5; i*i<=num; i+=6){
		if(num%i == 0 || num%(i+2) == 0) return 0;
	}
	return 1;
}


int is_very_prime(int n){
	int prev = 10;
	while(n != 0){
		int tmp = n%10;
		n /= 10;
		if(tmp > prev) return 0;
		else prev = tmp;
	}
	return 1;
}


int main(void){
	int n;
	scanf("%d", &n);
	for(int i=2; i<n; i++){
		if(is_prime(i)){
			if(is_very_prime(i)) printf("%d\n", i);
		}
	}
}
