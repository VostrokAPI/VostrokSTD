#include <stdio.h>
#include <string.h>

#include "_vs_std.h"
#include "greatest.h"

TEST	vs_strlen_slow_null(void)
{
	ASSERT_EQ(__vs_strlen_slow(NULL), 0);
	PASS();
}

SUITE(the_suite) {
	RUN_TEST(vs_strlen_slow_null);
}

GREATEST_MAIN_DEFS();

int main(int argc, char **argv)
{
	GREATEST_MAIN_BEGIN();

	RUN_SUITE(the_suite);

	GREATEST_MAIN_END();
	return (0);
}
