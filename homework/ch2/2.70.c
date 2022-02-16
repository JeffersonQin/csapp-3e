#include <stdio.h>

/*
 * Return 1 when x can be represented as an n-bit, 2’s complement number;
 * 0 otherwise
 * Assume 1 <= n <= w
 */
int fits_bits(int x, int n) {
	return !(x >> n) || !((x >> n) + 1);
}

int main() {
	printf("%d\n", fits_bits(0xFFFF, 16));
	printf("%d\n", fits_bits(0xFFFF, 15));
	return 0;
}