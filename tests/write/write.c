#include "greatest.h"
#include "vs_std.h"
#include <asm-generic/errno-base.h>
#include <unistd.h>
#include <errno.h>

TEST	write_basic_test(void)
{
	char	buf[2][0x10];
	int 	fds[2][2] = {{0, 0}, {0, 0}};
	int		status[2] = {0, 0};

	memset(buf[0], 0, sizeof(buf[0]));
	memset(buf[1], 0, sizeof(buf[1]));
	ASSERT_NEQ(pipe(fds[0]), -1);
	ASSERT_NEQ(pipe(fds[1]), -1);
	status[0] = vs_write(fds[0][1], "hello", 5);
	status[1] = write(fds[1][1], "hello", 5);
	close(fds[1][1]);
	close(fds[0][1]);
	ASSERT_EQ(status[0], status[1]);
	status[0] = vs_read(fds[0][0], buf[0], sizeof(buf[0]));
	status[1] = read(fds[1][0], buf[1], sizeof(buf[1]));
	close(fds[0][0]);
	close(fds[1][0]);
	ASSERT_EQ(status[0], status[1]);
	ASSERT_STR_EQ(buf[0], buf[1]);
	PASS();
}

TEST	write_badfd_test(void)
{
	int status = 0;

	status = vs_write(0x20, "hello", 5);
	ASSERT_EQ_FMT(status, -1, "%d");
	ASSERT_EQ_FMT(errno, EBADF, "%d");
	PASS();
}

TEST	write_null_buf(void)
{
	int	status = 0;

	status = vs_write(VS_STDOUT, NULL, 5);

	ASSERT_EQ_FMT(status, -1, "%d");
	ASSERT_EQ_FMT(errno, EFAULT, "%d");
	PASS();
}

TEST	write_badsize(void)
{
	int	status = 0;

	status = vs_write(VS_STDOUT, "hello", 0);
	ASSERT_EQ_FMT(status, 0, "%d");
	PASS();
}

SUITE(write_test)
{
	RUN_TEST(write_basic_test);
	RUN_TEST(write_badfd_test);
	RUN_TEST(write_null_buf);
	RUN_TEST(write_badsize);
}

GREATEST_MAIN_DEFS();

int main(int argc, char **argv)
{
	GREATEST_MAIN_BEGIN();

	RUN_SUITE(write_test);

	GREATEST_MAIN_END();
	return (0);
}
