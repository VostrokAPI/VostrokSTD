#include <stdio.h>
#include <string.h>

#include "_vs_std.h"
#include "vs_std_test_utils.h"
#include "greatest.h"

TEST	vs_strlen_slow_null(void)
{
	ASSERT_EQ(__vs_strlen_slow(NULL), 1);
	PASSm(VS_TICK "  Test passed !");
}

SUITE(strlen_tests) {
	RUN_TEST(vs_strlen_slow_null);
}

GREATEST_MAIN_DEFS();

int main(int argc, char **argv)
{
	GREATEST_MAIN_BEGIN();

	RUN_SUITE(strlen_tests);

	GREATEST_MAIN_END();
	return (0);
}
