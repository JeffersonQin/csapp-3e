#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <pthread.h>

typedef unsigned float_bits;

float_bits float_i2f(int i) {
	unsigned sign = i < 0;
	unsigned ai = (i < 0) ? -i : i;
	unsigned exp = 127 + 31;
	unsigned frac = 0;
	unsigned residue;

	if (ai == 0) {
		exp = 0;
		frac = 0;
	} else {
		while (!((1 << 31) & ai)) {
			ai <<= 1;
			exp --;
		}
		// Now frac is at 30:8, 7:0 are residue, 31 is the implied leading one
		residue = ai & 0xFF;
		frac = (ai >> 8) & 0x7FFFFF;
		if (residue > 0x80 || (residue == 0x80 && (frac & 0x1))) {
			// round up
			frac ++;
			// might need to renormalize
			if (frac > 0x7FFFFF) {
				frac = 0;
				exp ++;
			}
		}
	}
	return (sign << 31) | (exp << 23) | frac;
}

float_bits float_i2f_true(int i) {
	float f = (float) i;
	return *((float_bits *) &f);
}

struct arg_struct {
	int start;
	int end;
	int step;
};

void assert(int x) {
	if (float_i2f(x) != float_i2f_true(x)) 
	printf("Test failed: \nTest case: %d, MY: 0x%x, ANS: 0x%x\n", 
		x, float_i2f(x), float_i2f_true(x));
}

void *test_method(void *args) {
	struct arg_struct *pargs = (struct arg_struct *) args;
	int start = pargs->start;
	int end = pargs->end;
	int step = pargs->step;
	for (int i = start; i <= end; i += step)
		assert(i);
}

int main() {
	const int thread_count = 24;
	pthread_t t[thread_count];

	// 0
	assert(0);
	// INT_MAX, INT_MIN
	assert(INT32_MAX);
	assert(INT32_MIN);
	// round up and renormalize
	assert(0x7FFFFF80);

	printf("limited sample passed.\n");

	// all test cases
	for (int i = 0; i < thread_count; i ++) {
		struct arg_struct args;
		args.start = INT32_MIN + i;
		args.end = INT32_MAX;
		args.step = thread_count;
		if (pthread_create(t + i, NULL, &test_method, (void *) &args) != 0)
			printf("Thread %d failed to start\n", i + 1);
	}

	for (int i = 0; i < thread_count; i ++) {
		if (pthread_join(*(t + i), NULL) != 0)
			printf("Thread %d failed to join\n", i + 1);
	}

	return 0;
}