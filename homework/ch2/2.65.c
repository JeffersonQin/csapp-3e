#include <stdio.h>

/* Return 1 when x contains an odd number of 1s; 0 otherwise. Assume w=32 */
int odd_ones(unsigned x) {
	unsigned p16 = (x >> 16) ^ x;
	unsigned p8 = (p16 >> 8) ^ p16;
	unsigned p4 = (p8 >> 4) ^ p8;
	unsigned p2 = (p4 >> 2) ^ p4;
	unsigned p1 = (p2 >> 1) ^ p2;
	return p1 & 1;
}

int main() {
	printf("%d\n", odd_ones(0xFFFF));
	printf("%d\n", odd_ones(0xFFFE));
	return 0;
}