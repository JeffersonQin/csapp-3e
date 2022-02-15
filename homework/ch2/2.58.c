#include <stdio.h>

int is_big_endian() {
	int x = 1;
	char *p = (char *) &x;
	return !(*p);
}

int main() {
	printf("%d\n", is_big_endian());
	return 0;
}