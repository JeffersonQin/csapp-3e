#include <stdio.h>

int condition(int x) {
	int shift_val = (sizeof(int) - 1) << 3;
	return (!x) || (!~x) || (!~((x & 0xFF) | ~0xFF)) || (!(x >> shift_val));
}

int main() {
	// 1
	printf("%d\n", condition(0xFFFFFFFF));
	printf("%d\n", condition(0));
	printf("%d\n", condition(0x123456FF));
	printf("%d\n", condition(0x123456));
	// 0
	printf("%d\n", condition(0x01123456));
	printf("%d\n", condition(0x123456F0));
	printf("%d\n", condition(0x123456F));
	return 0;
}