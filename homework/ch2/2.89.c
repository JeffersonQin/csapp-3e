#include <stdio.h>
#include <stdint.h>

int main() {
	int x = 0x64E73387;
	int y = 0x2CE34D9C;
	int z = 0x2DD0E033;
	
	double dx = (double) x;
	double dy = (double) y;
	double dz = (double) z;

	printf("%d\n", (dx * dy) * dz == dx * (dy * dz));
	return 0;
}