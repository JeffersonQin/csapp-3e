#include <stdio.h>

typedef unsigned packed_t;

int xbyte(packed_t word, int bytenum) {
	int left = word << ((3 - bytenum) << 3);
	return left >> 24;
}

int main() {
	printf("%d\n", xbyte(0xFFFF, 1));
	return 0;
}