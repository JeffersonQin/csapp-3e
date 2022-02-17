#include <stdio.h>

unsigned A(int k) {
	return ~((1 << k) - 1);
}

unsigned B(int j, int k) {
	return ((1 << k) - 1) << j;
}

int main() {
	printf("%d\n", A(5));
	printf("%d\n", B(5, 6));
	return 0;
}