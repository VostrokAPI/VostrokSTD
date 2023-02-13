#include "greatest.h"
#include <string.h>
#include <stdlib.h>

TEST	atoi_basic_test1(void)
{
	PASS();
}

TEST	atoi_basic_test2(void)
{
	PASS();
}

TEST	atoi_basic_test3(void)
{
	PASS();
}

TEST	atoi_basic_test4(void)
{
	PASS();
}

TEST	atoi_basic_test5(void)
{
	PASS();
}

TEST	atoi_basic_test6(void)
{
	PASS();
}

TEST	atoi_basic_test7(void)
{
	PASS();
}

TEST	atoi_basic_test8(void)
{
	PASS();
}

TEST	atoi_basic_test9(void)
{
	PASS();
}

TEST	atoi_basic_test10(void)
{
	PASS();
}

SUITE(atoi_basic_test)
{
	RUN_TEST(atoi_basic_test1);
	RUN_TEST(atoi_basic_test2);
	RUN_TEST(atoi_basic_test3);
	RUN_TEST(atoi_basic_test4);
	RUN_TEST(atoi_basic_test5);
	RUN_TEST(atoi_basic_test6);
	RUN_TEST(atoi_basic_test7);
	RUN_TEST(atoi_basic_test8);
	RUN_TEST(atoi_basic_test9);
	RUN_TEST(atoi_basic_test10);

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
