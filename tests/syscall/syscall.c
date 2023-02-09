#include <stdio.h>
#include "greatest.h"
#include "vs_syscall.h"
#include <unistd.h>

/////////////////////////////
//
//		SYSCALL TEST
//
/////////////////////////////

TEST	vs_syscall_getcwd(void)
{
	char	buf[2][0x100];

	getcwd(buf[0], sizeof(buf[0]));
	vs_syscall(VS_SYS_GETCWD, buf[1], sizeof(buf[1]));
	ASSERT_STR_EQ(buf[0], buf[1]);
	PASS();
}

GREATEST_MAIN_DEFS();

SUITE(syscall_test)
{
	RUN_TEST(vs_syscall_getcwd);
}

int main(int argc, char **argv)
{
	GREATEST_MAIN_BEGIN();

	RUN_SUITE(syscall_test);

	GREATEST_MAIN_END();

	return (0);
}
