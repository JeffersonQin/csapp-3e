#include <stdio.h>

int main() {
	int x = 0x89ABCDEF;
	int y = 0x76543210;
	int ans = (x & 0xFF) | (y & ~0xFF);
	printf("%x\n", ans);
	return 0;
}
