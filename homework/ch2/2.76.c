#include <stdlib.h>
#include <stdio.h>
#include <memory.h>

void *calloc(size_t nmemb, size_t size) {
	if (nmemb == 0 || size == 0)
		return NULL;
	size_t msize = nmemb * size;
	void *p = malloc(msize);
	memset(p, 0, msize);
	return p;
}