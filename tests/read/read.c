#include "greatest.h"
#include <unistd.h>
#include <errno.h>
#include "vs_std.h"
#include "vs_types.h"

TEST	read_basic_test(void)
{
	char	buf[0x10];
	int		fds[2] = {0, 0};

	ASSERT_NEQ(pipe(fds), -1);
	write(fds[1], "hello world", 11);
	close(fds[1]);
	ASSERT_EQ(vs_read(fds[0], buf, sizeof(buf)), 11);
	close(fds[0]);
	PASS();
}

TEST	read_null_buf(void)
{
	int		fds[2] = {0, 0};

	ASSERT_NEQ(pipe(fds), -1);
	write(fds[1], "hello world", 11);
	close(fds[1]);
	ASSERT_EQ_FMT(vs_read(fds[0], NULL, 5), -1, "%d");
	ASSERT_EQ_FMT(errno, EFAULT, "%d");
	close(fds[0]);
	PASS();
}

TEST	read_zero_size(void)
{
	char	buf[0x10];
	int		fds[2] = {0, 0};

	ASSERT_NEQ(pipe(fds), -1);
	write(fds[1], "hello world", 11);
	close(fds[1]);
	ASSERT_EQ(vs_read(fds[0], buf, 0), 0);
	close(fds[0]);
	PASS();
}

SUITE(read_test)
{
	RUN_TEST(read_basic_test);
	RUN_TEST(read_null_buf);
	RUN_TEST(read_zero_size);
}

GREATEST_MAIN_DEFS();

int main(int argc, char **argv)
{
	GREATEST_MAIN_BEGIN();
	
	RUN_SUITE(read_test);

	GREATEST_MAIN_END();
	return (0);
}
