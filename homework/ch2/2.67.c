#include <stdio.h>

// A. C standard only defined << 1 ~ << (w - 1), << w is not defined.
// B.
int int_size_is_32_least_32() {
	int set_msb = 1 << 31;
	int beyond_msb = 2 << 31;
	return set_msb && !beyond_msb;
}

// C.
int int_size_is_32_least_16() {
	int set_msb = 2 << 15 << 15;
	int beyond_msb = set_msb << 1;
	return set_msb && !beyond_msb;
}

int main() {
	printf("%d\n", int_size_is_32_least_32());
	printf("%d\n", int_size_is_32_least_16());
	return 0;
}