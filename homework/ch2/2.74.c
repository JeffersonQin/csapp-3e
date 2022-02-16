#include <stdio.h>

int tsub_ok(int x, int y) {
	int diff = x - y;
	int neg_overflow = x < 0 && y > 0 && diff >= 0;
	int pos_overflow = x >= 0 && y < 0 && diff < 0;
	return !neg_overflow && !pos_overflow;
}

int main() {
	printf("%d\n", tsub_ok(2, 54)); // 1
	printf("%d\n", tsub_ok(0xFFFFFFFF, 0x80000000)); // 1
	printf("%d\n", tsub_ok(0, 0x80000000)); // 0
	printf("%d\n", tsub_ok(0, 0x80000001)); // 1
	printf("%d\n", tsub_ok(0, 0)); // 1
	printf("%d\n", tsub_ok(1, 0x80000000)); // 0
	return 0;
}