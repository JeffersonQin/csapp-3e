#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <pthread.h>

typedef unsigned float_bits;

int float_f2i(float_bits f) {
	unsigned sign = f >> 31;
	unsigned exp = (f >> 23) & 0xFF;
	unsigned frac = f & 0x7FFFFF;
	/* Create normalized value with leading one inserted,
	 * and rest of significand in bits 8--30. 
	 */
	unsigned val = 0x80000000u | (frac << 8);
	// E is less than zero, absolute value < 1.
	if (exp < 127) return 0;
	if (exp > 158) return (int) 0x80000000u;
	val >>= 158 - exp;
	if (sign) {
		// Negative
		return val > 0x80000000u ? (int) 0x80000000u : -(int) val;
	} else {
		// Positive
		return val > 0x7FFFFFFF ? (int) 0x80000000u : (int) val;
	}
}

int float_f2i_true(float_bits f) {
	float fl = *((float *) &f);
	if (isnan(fl)) return (int) 0x80000000u;
	if (fl > (float) INT32_MAX || fl < (float) INT32_MIN)
		return (int) 0x80000000u;
	return (int) fl;
}

struct arg_struct {
	int start;
	int end;
	int step;
};

void assert(unsigned x) {
	if (float_f2i(x) != float_f2i_true(x)) 
	printf("Test failed: \nTest case: 0x%x, MY: %d, ANS: %d\n", 
		x, float_f2i(x), float_f2i_true(x));
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

	float int_max = (float) INT32_MAX;
	float int_min = (float) INT32_MIN;
	float int_max_p1 = int_max + 1;
	float int_min_m1 = int_min - 1;
	assert(*((unsigned *) &int_max));
	assert(*((unsigned *) &int_min));
	assert(*((unsigned *) &int_max_p1));
	assert(*((unsigned *) &int_min_m1));

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