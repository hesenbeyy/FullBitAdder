#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "binary.h"
#include "octal.h"
#include "hexadecimal.h"


int main() {
	printf("Welcome to Full-Adder!\n");
	while (1) {
		int total;
		int sum;
		int c_out;
		int user_choice;

		printf("(1) Compute and display the outputs\n(2) Quit\nYour choice: ");
		if (scanf("%d",&user_choice) != 1) {
			printf("Invalid input. Please enter numbers.\n");
			while (getchar() != '\n');
			continue;
		}
		if (user_choice == 1) {
			int base;
			while (1) {
				printf("Which base will you use to enter input (base 16/8/2)?\n");
				if (scanf("%d", &base) != 1) {
					printf("Invalid input. Please enter a number.\n");
					while (getchar() != '\n');
					continue;
				}
				break;
			}

			switch (base) {
			case 2:
				total = binary_eval();
				break;
			case 8:
				total = octal_eval();
				break;
			case 16:
				total = hexa_eval();
				break;
			default:
				printf("Invalid base conversion. Please enter one of the basis 2,8,16.\n");
				while (getchar() != '\n');
				continue;
			}
			switch (total) {
			case 0:
				sum = 0;
				c_out = 0;
				break;
			case 1:
				sum = 1;
				c_out = 0;
				break;
			case 2:
				sum = 0;
				c_out = 1;
				break;
			case 3:
				sum = 1;
				c_out = 1;
				break;
			default:
				printf("lmao how did you get there\n");
				break;
			}
			printf("Sum is %d, Carry-out is %d.\n", sum, c_out);
		}
		else if (user_choice == 2) {
			printf("Thank you for using Full-Adder!\n");
			return 0;
		}
		else {
			printf("Invalid input. Please enter 1 or 2.\n");
			continue;
		}
	}
}