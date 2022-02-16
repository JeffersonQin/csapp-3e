#include <stdio.h>

int m17(int x) {
	return x + (x << 4);
}

int mn7(int x) {
	return x - (x << 3);
}

int m60(int x) {
	return (x << 6) - (x << 2);
}

int mn112(int x) {
	return -(x << 7) + (x << 4);
}

int main() {
	printf("%d\n", m17(2));
	printf("%d\n", mn7(2));
	printf("%d\n", m60(2));
	printf("%d\n", mn112(2));
	return 0;
}