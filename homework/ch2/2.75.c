#include <stdio.h>

int signed_high_prod(int x, int y);

unsigned unsigned_high_prod(unsigned x, unsigned y) {
	unsigned p = (unsigned) signed_high_prod((int) x, (int) y);
	int wm1 = (sizeof(int) << 3) - 1;
	p += y * (x >> wm1) + x * (y >> wm1);
	return p;
}
