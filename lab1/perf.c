#include <stdio.h>
#include <math.h>


int main(void){
	int m, n;
	int counter = 0;
	int tab[10];
	int x = 0;
	scanf("%i", &m);
	scanf("%i", &n);

	if(m%2 == 1) m++;
	for(int i=m; i<=n; i+=2){
		int sum = 0;
		sum += 1;
		for(int j=2; j<=sqrt(i); j++){
			if(i%j == 0){
				sum += j;
				sum += i/j;
			}
		}
		if(sum == i){
			counter++;
			tab[x] = i;
			x++;
		}
	}
	printf("%d\n", counter);
	for(int i=0; i<counter; i++){
		printf("%d ", tab[i]);
	}
}

