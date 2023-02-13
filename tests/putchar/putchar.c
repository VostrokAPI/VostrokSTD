#include "greatest.h"
#include <stdio.h>
#include <vs_std.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

TEST	putchar_basic(void)
{
	int		fds[2] = {0, 0};
	pid_t	pid = 0;
	int		value = 0;

	ASSERT_NEQ(pipe(fds), -1);
	pid = fork();
	if (!pid)
	{
		close(fds[0]);
		dup2(fds[1], 1);
		vs_putchar('A');
		exit(0);
	}
	close(fds[1]);
	wait(NULL);
	ASSERT_EQ(read(fds[0], &value, sizeof(int)), sizeof(int));
	close(fds[0]);
	ASSERT_EQ(value, 'A');
	PASS();
}

TEST	putchar_short(void)
{
	int		fds[2] = {0, 0};
	pid_t	pid = 0;
	int		value = 0;

	ASSERT_NEQ(pipe(fds), -1);
	pid = fork();
	if (!pid)
	{
		close(fds[0]);
		dup2(fds[1], 1);
		vs_putchar(0xFFFF);
		exit(0);
	}
	close(fds[1]);
	wait(NULL);
	ASSERT_EQ(read(fds[0], &value, sizeof(int)), sizeof(int));
	close(fds[0]);
	ASSERT_EQ(value, 0xFFFF);
	PASS();
}

SUITE(putchar_test)
{
	RUN_TEST(putchar_basic);
	RUN_TEST(putchar_short);
}

GREATEST_MAIN_DEFS();

int main(int argc, char **argv)
{
	GREATEST_MAIN_BEGIN();
	RUN_SUITE(putchar_test);
	GREATEST_MAIN_END();
	return (0);
}
