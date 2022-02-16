#include <stdio.h>

int lower_one_mask(int n) {
	return (2 << (n - 1)) - 1;
}

int main() {
	printf("%x\n", lower_one_mask(6));
	printf("%x\n", lower_one_mask(17));
	return 0;
}