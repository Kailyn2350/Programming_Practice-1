#include <stdio.h>

int main(void) {
	int num;
	int a_binary_number[16] = { 0, };//arrangement in order to express of 16bits

	printf("Please input the number : ");
	scanf_s("%d", &num);

	for (int i = 0; num > 0; i++) {
		a_binary_number[i] = num % 2;//input the remainder in arrangement
		num = num / 2;//changing of quotient
	}

	for (int i = 0; i <= 15; i++) {
		printf("%d", a_binary_number[15-i]);//print reverse order
		if ((i+1) % 4 == 0) {
			printf(" ");//leave a space between byte
		}

	}

	return 0;
}
