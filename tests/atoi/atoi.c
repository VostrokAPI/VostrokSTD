#include "greatest.h"
#include "vs_types.h"
#include "vs_std.h"
#include "vs_rand.h"
#include <string.h>
#include <stdlib.h>

TEST	atoi_basic_test_routine(void)
{
	char	buf[0x10];
	int		i = (int)vs_rdrandshort();
	static int	cnt = 0;

	memset(buf, 0, sizeof(buf));
	if (!(cnt++ & 1))
		i = ~(i - 1);
	vs_itos(i, buf, sizeof(buf));
	ASSERT_EQ_FMT(vs_atoi(buf), i, "%d");
	PASS();
}

SUITE(atoi_basic_test)
{
	for (int i = 0; i < 20; i++)
		RUN_TEST(atoi_basic_test_routine);
}

TEST	atoi_crash_test1(void)
{
	ASSERT_EQ_FMT(vs_atoi(""), 0, "%d");
	PASS();
}

TEST	atoi_crash_test2(void)
{
	ASSERT_EQ_FMT(vs_atoi(NULL), 0, "%d");
	PASS();
}

SUITE(atoi_crash_test)
{
	RUN_TEST(atoi_crash_test1);
	RUN_TEST(atoi_crash_test2);
}

GREATEST_MAIN_DEFS();

int main(int argc, char **argv)
{
	GREATEST_MAIN_BEGIN();

	RUN_SUITE(atoi_basic_test);
	RUN_SUITE(atoi_crash_test);

	GREATEST_MAIN_END();
	return (0);
}
