#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "../include/octal.h"

int octal_eval() {
	int octal_input;
	char extra;
	printf("Please enter your octal input: ");
	while (1){
		if (scanf("%o%c", &octal_input, &extra) == 2 && extra == '\n') {
			if (octal_input > 7 || octal_input < 0) {
				printf("Invalid input. Octal %o cannot be represented in 3-bits!\n",octal_input);
				continue;
			}
			int first_number = (octal_input / 4) % 2;
			int second_number = (octal_input / 2) % 2;
			int third_number = (octal_input / 1) % 2;

			return (first_number + second_number + third_number);
		}
	}
}