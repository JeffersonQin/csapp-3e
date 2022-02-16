#include <stdio.h>
#include <stdint.h>

int saturating_add(int x, int y) {
	int sum = x + y;
	int wm1 = (sizeof(int) << 3) - 1;
	int xs = x >> wm1;
	int ys = y >> wm1;
	int ss = sum >> wm1;
	int pos_overflow = ~xs & ~ys & ss;
	int neg_overflow = xs & ys & ~ss;
	int normal = ~(pos_overflow | neg_overflow);
	return (normal & sum) | (pos_overflow & INT32_MAX) | (neg_overflow & INT32_MIN);
}

void test(int x, int y) {
	printf("0x%x + 0x%x => 0x%x\n", x, y, saturating_add(x, y));
}

int main() {
	test(0x7FFFFFFF, 0x7FFFFFFF);
	test(0xFFFFFFFF, 0xFFFFFFFF);
	test(0x80000000, 0x90000000);
	test(0x7FFFFFFF, 0xFFFFFFFF);
	return 0;
}