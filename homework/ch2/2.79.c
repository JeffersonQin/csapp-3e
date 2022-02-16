#include <stdio.h>

int mul3div4(int x) {
	int mul3 = x + (x << 1);
	int wm1 = (sizeof(int) << 3) - 1;
	int bias = (x >> wm1) & 3;
	return (mul3 + bias) >> 2;
}

int test(int x) {
	int my = mul3div4(x), ans = x * 3 / 4;
	printf("%d: %x %x\n", my == ans, my, ans);
}

int main() {
	test(0xFFFFFFFF);
	test(0x7FFFFFFF);
	test(0x80000000);
	test(0x80000001);
	test(0x12345678);
	test(0xF2345678);
	return 0;
}