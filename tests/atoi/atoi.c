#include "greatest.h"
#include "vs_types.h"
#include "vs_std.h"
#include "vs_rand.h"
#include <string.h>
#include <stdlib.h>

TEST	atoi_basic_test_routine(void)
{
	PASS();
}

SUITE(atoi_basic_test)
{
	for (int i = 0; i < 10; i++)
		RUN_TEST(atoi_basic_test_routine);
}

TEST	atoi_overflow_test1(void)
{
	PASS();
}

TEST	atoi_overflow_test2(void)
{
	PASS();
}

TEST	atoi_overflow_test3(void)
{
	PASS();
}

SUITE(atoi_overflow_test)
{
	RUN_TEST(atoi_overflow_test1);
	RUN_TEST(atoi_overflow_test2);
	RUN_TEST(atoi_overflow_test3);
}

TEST	atoi_crash_test1(void)
{
	PASS();
}

SUITE(atoi_crash_test)
{
	RUN_TEST(atoi_crash_test1);
}

GREATEST_MAIN_DEFS();

int main(int argc, char **argv)
{
	GREATEST_MAIN_BEGIN();

	RUN_SUITE(atoi_basic_test);
	RUN_SUITE(atoi_overflow_test);
	RUN_SUITE(atoi_crash_test);

	GREATEST_MAIN_END();
	return (0);
}
