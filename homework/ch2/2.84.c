#include <stdio.h>

int float_le(float x, float y) {
	unsigned ux = *((unsigned *) &x);
	unsigned uy = *((unsigned *) &y);

	unsigned sx = ux >> 31;
	unsigned sy = uy >> 31;

	return (!sx && !sy && sx <= sy) // x >= 0, y >= 0
		|| (sx && !sy) // x < 0, y >= 0
		|| (sx && sy && sx >= sy) // x < 0, y < 0
		|| (!(ux << 1) && !(uy << 1));
}

int float_le_true(float x, float y) {
	return x <= y;
}

void test(float x, float y) {
	int my = float_le(x, y), ans = float_le_true(x, y);
	printf("%d: %d %d\n", my == ans, my, ans);
}

int main() {
	test(1.0, 1.0);
	test(0.0, 0.0);
	test(-1.0, 1.0);
	test(-2.0, 3.0);
	test(2.0, -1.0);
	return 0;
}
