#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <pthread.h>

typedef unsigned float_bits;

float_bits float_abs(float_bits f) {
	unsigned exp = (f >> 23) & 0xFF;
	unsigned frac = f & 0x7FFFFF;
	unsigned mask = ~(1 << 31);
	unsigned abs = f & mask;
	if (exp == 0xFF && frac) return f;
	return abs;
}

float_bits float_abs_true(float_bits f) {
	float fl = *((float *) &f);
	if (isnan(fl)) return f;
	if (fl == -0.0) return 0.0;
	if (fl < 0) fl = -fl;
	return *((float_bits *) &fl);
}

struct arg_struct {
	int start;
	int end;
	int step;
};

void assert(unsigned x) {
	if (float_abs(x) != float_abs_true(x)) 
	printf("Test failed: \nTest case: 0x%x, MY: 0x%x, ANS: 0x%x\n", 
		x, float_abs(x), float_abs_true(x));
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
	// smallest denormalized
	assert(0x1);
	assert(0x80000001u);
	// largest denormalized
	assert(0x7FFFFF);
	assert(0x807FFFFFu);
	// smallest normalized
	assert(0x800000);
	assert(0x80800000u);
	// largest normalized
	assert(0x7F7FFFFF);
	assert(0xFF7FFFFFu);
	// NaN
	assert(0x7F800001);
	assert(0xFF800001u);
	// infinity
	assert(0x7F800000);
	assert(0xFF800000u);

	printf("limited sample passed.\n");

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