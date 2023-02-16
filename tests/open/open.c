#include <fcntl.h>
#define _GNU_SOURCE
#include "greatest.h"
#include "vs_std.h"
#include "vs_types.h"
#include <unistd.h>
#include <errno.h>

TEST	open_basic_test1(void)
{
	int fd = vs_open("test.txt", O_CREAT | O_RDWR, S_IRUSR);

	ASSERT_NEQ(fd, -1);
	close(fd);
	unlink("test.txt");
	PASS();
}

TEST	open_basic_test2(void)
{
	int fd = vs_open("notfound", O_RDONLY, S_IRUSR);

	ASSERT_EQ(fd, -1);
	ASSERT_EQ(errno, ENOENT);
	PASS();
}

SUITE(open_basic_test)
{
	RUN_TEST(open_basic_test1);
	RUN_TEST(open_basic_test2);
}

GREATEST_MAIN_DEFS();

int main(int argc, char **argv)
{
	GREATEST_MAIN_BEGIN();

	RUN_SUITE(open_basic_test);

	GREATEST_MAIN_END();
	return (0);
}
