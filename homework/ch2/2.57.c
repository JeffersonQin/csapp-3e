#include <stdio.h>
#include <string.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len) {
    size_t i;
    for (i = 0; i < len; i++)
	printf(" %.2x", start[i]);
    printf("\n");
}

void show_int(int x) {
    show_bytes((byte_pointer) &x, sizeof(int));
}

void show_float(float x) {
    show_bytes((byte_pointer) &x, sizeof(float));
}

void show_pointer(void *x) {
    show_bytes((byte_pointer) &x, sizeof(void *));
}

void show_short(short x) {
	show_bytes((byte_pointer) &x, sizeof(short));
}

void show_double(double x) {
	show_bytes((byte_pointer) &x, sizeof(double));
}

void show_long(long x) {
	show_bytes((byte_pointer) &x, sizeof(long));
}

int main() {
	show_int(0x12345678);
	show_float(0.123456789);
	show_short(0x1234);
	show_double(0.123456789012345);
	show_long(0x12345678);
    return 0;
}
