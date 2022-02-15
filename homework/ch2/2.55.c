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

void test_show_bytes(int val) {
    int ival = val;
    float fval = (float) ival;
    int *pval = &ival;
    show_int(ival);
    show_float(fval);
    show_pointer(pval);
}

void simple_show_a() {
	int val = 0x87654321;
	show_int(val);
}

void simple_show_b() {
	int val = 0x12345678;
	show_int(val);
}

void float_eg() {
	int x = 3490593;
	float f = (float) x;
	printf("For x = %d\n", x);
	show_int(x);
	show_float(f);

	x = 3510593;
	f = (float) x;
	printf("For x = %d\n", x);
	show_int(x);
	show_float(f);
}

void string_ueg() {
	const char *s = "ABCDEF";
	show_bytes((byte_pointer) s, strlen(s)); 
}

void string_leg() {
	const char *s = "abcdef";
	show_bytes((byte_pointer) s, strlen(s)); 
}

void show_twocomp() {
    short x = 12345; 
    short mx = -x; 
    
    show_bytes((byte_pointer) &x, sizeof(short)); 
    show_bytes((byte_pointer) &mx, sizeof(short)); 
}

int main() {
	test_show_bytes(54367);
	simple_show_a();
	simple_show_b();
	float_eg();
	string_ueg();
	string_leg();
	show_twocomp();
    return 0;
}
