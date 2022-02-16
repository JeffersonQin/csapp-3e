#include <stdio.h>

int threefourths(int x) {
	int s1 = x >> 1, s2 = x >> 2;
	int wm1 = (sizeof(int) << 3) - 1;
	int bias = (x >> wm1) & 3;
	int incr = (((x & 1) << 1) + (x & 3) + bias) >> 2;
	return s1 + s2 + incr;
}

int big_threefourths(int x) {
	long long n = (long long) x;
	return (int) (x * 3LL / 4LL);
}

void test(int x) {
	int my = threefourths(x), ans = big_threefourths(x);
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