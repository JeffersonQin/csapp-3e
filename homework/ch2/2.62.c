#include <stdio.h>

int int_shift_are_arithmetic() {
	int x = -1;
	return !~((x >> 1) & x);
}

int main() {
	printf("%d\n", int_shift_are_arithmetic());
	return 0;
}