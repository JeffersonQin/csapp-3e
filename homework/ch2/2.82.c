#include <stdio.h>
#include <stdint.h>

int main() {
	// A, not true
	printf("%d\n", (INT32_MIN < 0) == (-INT32_MIN > -0));
	// B, true
	// C, true
	// D, true
	// E, true
	return 0;
}