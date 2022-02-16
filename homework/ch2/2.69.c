#include <stdio.h>

unsigned rotate_left(unsigned x, int n) {
	int w = sizeof(int) << 3;
	unsigned mask = ((1 << n) - 1) << (w - n);
	return ((mask & x) >> (w - n)) + (x << n);
}

int main() {
	printf("%x\n", rotate_left(0x12345678, 4));
	printf("%x\n", rotate_left(0x12345678, 20));
	return 0;
}