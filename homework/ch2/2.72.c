#include <memory.h>
#include <stdio.h>

void copy_int(int val, void *buf, int maxbytes) {
	if (maxbytes >= sizeof(val))
		memcpy(buf, (void *) &val, sizeof(val));
}

int main() {
	return 0;
}
