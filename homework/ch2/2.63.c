#include <stdio.h>
#include <stdint.h>

/* logical shift right */
unsigned srl(unsigned x, int k) {
	/* Perform shift arithmetically */
	unsigned xsra = (int) x >> k;
	int w = sizeof(int) << 3;
	int64_t mask = ((int64_t) 1 << (w - k)) - 1; // tried not to use ?: and if
	return xsra & (unsigned) mask;
}

/* arithmetical shift right */
int sra(int x, int k) {
	/* Perform shift logically */
	int xsrl = (unsigned) x >> k;
	int w = sizeof(int) << 3;
	unsigned mask = k ? ~((1 << (8*sizeof(int)-k)) - 1) : 0;
	return (x < 0) ? mask | xsrl : xsrl;
}

int main() {
	printf("%x\n", srl(0x12345678, 0));
	printf("%x\n", srl(0x12345678, 4));
	printf("%x\n", srl(0x12345678, 8));
	printf("%x\n", srl(0x12345678, 10));

	printf("%x\n", sra(0xF2345678, 0));
	printf("%x\n", sra(0xF2345678, 4));
	printf("%x\n", sra(0xF2345678, 8));
	printf("%x\n", sra(0xF2345678, 10));
	return 0;
}