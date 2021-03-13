#include <stdio.h>

int main(void){
	int f_1 = 0;
	int f_2 = 1;
	int number;
	scanf("%d", &number);

	while (f_1*f_2 < number){
		int tmp = f_1+f_2;
		f_1 = f_2;
		f_2 = tmp;
	}
	if (f_1*f_2 == number) printf("YES");
	else printf("NO");
	printf("\n");
}
