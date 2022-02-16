#include <stdio.h>

/* Return 1 when any odd bit of x equals 1; 0 otherwise. Assume w=32 */
int any_odd_one(unsigned x) {
	unsigned mask = 0xAAAAAAAA;
	return !!(x & mask);
}

int main() {
	printf("%d\n", any_odd_one(1));
	printf("%d\n", any_odd_one(5));
	printf("%d\n", any_odd_one(0xFFFF));
	return 0;
}