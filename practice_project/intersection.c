#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int set1_count, set2_count, intersection_count = 0;
static int call_index;

int* set_element_adder();
int* intersection(int* a, int* b, int size_a, int size_b);
void print_set(int* set, int size);

int main() {
	int* set1, * set2, * intersection_set;

	printf("\nWelcome to the intersection of sets program! \n");

	set1 = set_element_adder();
	set2 = set_element_adder();

	print_set(set1, set1_count);
	print_set(set2, set2_count);

	intersection_set = intersection(set1, set2,set1_count,set2_count);
	intersection_set = (int*)realloc(intersection_set, sizeof(int) * intersection_count);
	if (!intersection_set) {
		printf("Error reallocating memory.\n");
		exit(1);
	}
	print_set(intersection_set, intersection_count);

	free(set1);
	free(set2);
	free(intersection_set);


	return 0;
}

int* set_element_adder() {

	int number_of_elements;
	printf("Please enter the number of elements: ");
	scanf("%d", &number_of_elements);

	int* set = (int*)malloc(sizeof(int) * number_of_elements);
	if (!set) {
		printf("Error. Couldn't allocate memory. \n");
		exit(1);
	}

	int* sp = set;
	for (int i = 0; i < number_of_elements; i++) {
		int user_input;
		printf("Enter element %d: ", i + 1);
		scanf("%d", &user_input);
		*(sp++) = user_input;
	}

	if (call_index) {
		set2_count = number_of_elements;
	}
	else {
		set1_count = number_of_elements;
	}

	call_index = 1;

	return set;
}

int* intersection(int* a, int* b, int size_a, int size_b) {
	int* intersection_set = (int*)malloc(sizeof(int) * (size_a >= size_b ? size_b : size_a));
	for (int i = 0; i < size_a; i++) {
		for (int j = 0; j < size_b; j++) {
			if (a[i] == b[j]) {
				int alreadyExists = 0;
				for (int k = 0; k < intersection_count; k++) {
					if (a[i] == intersection_set[k]) {
						alreadyExists = 1;
						break;
					}
				}
				if (!alreadyExists) {
					intersection_set[intersection_count++] = a[i];
				}
			}
		}
	}
	return intersection_set;
}
void print_set(int* set, int size) {
	printf("Elements of the set is: ");
	for (int i = 0; i < size; i++) {
		printf("%d ", set[i]);
	}
	printf("\n");
}
