#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "../include/hexadecimal.h"

int hexa_eval() {
	int hexadecimal_input;
	char extra;
	while (1) {
		printf("Please enter your hexadecimal integer: ");
		if (scanf("%x%c", &hexadecimal_input, &extra) == 2 && extra == '\n') {
			if (hexadecimal_input > 7 || hexadecimal_input < 0) {
				printf("Invalid input. Hexadecimal %X cannot be represented in 3-bits!\n", hexadecimal_input);
				continue;
			}
			int first_number = (hexadecimal_input / 4) % 2;
			int second_number = (hexadecimal_input / 2) % 2;
			int third_number = (hexadecimal_input / 1) % 2;

			return (first_number + second_number + third_number);
		}
		else {
			printf("Invalid input. Please input appropriate integers. \n");
			while (getchar() != '\n');
			continue;
		}
	}
}


