#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "binary.h"

int binary_eval() {
	int binary_input;
	char extra;
	while(1){
		printf("Please enter your binary input: ");
		if (scanf("%d%c", &binary_input, &extra) == 2 && extra == '\n') {
			if (binary_input > 111 || binary_input < 0) {
				printf("Invalid input. Please enter valid terms.\n");
				continue;
			}
			int first_number = binary_input / 100;
			int second_number = (binary_input / 10) % 10;
			int third_number = binary_input % 10;

			if (first_number != 0 && first_number != 1
				|| second_number != 0 && second_number != 1
				|| third_number != 0 && third_number != 1) {
				
				printf("Invalid input. Please enter only binary numbers.\n");
				continue;
			}
			else {
				return (first_number + second_number + third_number);
			}
		}
		else {
			printf("I dont really know what to say. You just crashed the binary input. Please enter valid binary digits.\n");
			while (getchar() != '\n');
			continue;
		}
	}
}