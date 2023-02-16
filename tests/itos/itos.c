#include "greatest.h"
#include "vs_std.h"
#include <stdio.h>

TEST	itos_basic_test1(void)
{
	char	buf[0x10];
	int	nbr = -123456789;

	memset(buf, 0, sizeof(buf));
	ASSERT_STR_EQ(vs_itos(nbr, buf, sizeof(buf)), "-123456789");
	PASS();
}

TEST	itos_basic_test2(void)
{
	char	buf[0x10];
	int		nbr = 1230040;

	memset(buf, 0, sizeof(buf));
	ASSERT_STR_EQ(vs_itos(nbr, buf, sizeof(buf)), "1230040");
	PASS();
}

SUITE(itos_test)
{
	RUN_TEST(itos_basic_test1);
	RUN_TEST(itos_basic_test2);
}

GREATEST_MAIN_DEFS();

int main(int argc, char **argv)
{
	GREATEST_MAIN_BEGIN();

	RUN_SUITE(itos_test);

	GREATEST_MAIN_END();
	return (0);
}
