#include <stdio.h>

int divide_power2(int x, int k) {
	int wm1 = (sizeof(int) << 3) - 1;
	int bias = (x >> wm1) & ((1 << k) - 1);
	return (x + bias) >> k;
}

int main() {
	printf("%d\n", divide_power2(10, 2));
	printf("%d\n", divide_power2(-10, 2));
	return 0;
}