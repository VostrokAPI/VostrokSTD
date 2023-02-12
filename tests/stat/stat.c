#include <stdio.h>
#include "greatest.h"
#include "vs_stat.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

TEST	stat_size_struct_test(void)
{
	struct stat	s;
	vs_stat_t	vs;

	ASSERT_EQ_FMT(sizeof(vs), sizeof(s), "%ld");
	PASS();
}

TEST	stat_basic_test(void)
{
	struct	stat	s;
	vs_stat_t		vs;

	memset(&s, 0, sizeof(s));
	memset(&vs, 0, sizeof(vs));
	ASSERT_EQ_FMT(stat("Makefile", &s), vs_stat("Makefile", &vs), "%d");
	ASSERT_MEM_EQ(&vs, &s, sizeof(s));
	PASS();
}

TEST	stat_file_no_exist(void)
{
	struct	stat	s;
	vs_stat_t		vs;

	memset(&s, 0, sizeof(s));
	memset(&vs, 0, sizeof(vs));
	ASSERT_EQ_FMT(vs_stat("notfound", &vs), stat("notfound", &s), "%d");
	ASSERT_MEM_EQ(&vs, &s, sizeof(struct stat));
	printf("%ld == %ld\n", vs.st_size, s.st_size);
	PASS();
}

TEST	fstat_file_test(void)
{
	vs_stat_t	vs;
	struct stat	s;
	int	fds[2] = {0, 0};

	fds[0] = open("Makefile", O_RDONLY, S_IRUSR);
	fds[1] = open("Makefile", O_RDONLY, S_IRUSR);

	memset(&vs, 0, sizeof(vs));
	memset(&s, 0, sizeof(s));
	ASSERT_EQ_FMT(fstat(fds[0], &vs), vs_fstat(fds[1], &s), "%d");
	ASSERT_MEM_EQ(&vs, &s, sizeof(struct stat));
	close(fds[0]);
	close(fds[1]);
	PASS();
}

TEST	fstat_badfile_test(void)
{
	vs_stat_t	vs;
	struct stat	s;
	int	fds[2] = {0, 0};
	int	status[2] = {0, 0};

	fds[0] = open("notfound", O_RDONLY, S_IRUSR);
	fds[1] = open("notfound", O_RDONLY, S_IRUSR);

	memset(&vs, 0, sizeof(vs));
	memset(&s, 0, sizeof(s));
	status[0] = fstat(fds[0], &s);
	status[1] = fstat(fds[1], &vs);
	ASSERT_EQ(status[0], status[1]);
	close(fds[0]);
	close(fds[1]);
	PASS();
}

SUITE(stat_test)
{
	RUN_TEST(stat_size_struct_test);
	RUN_TEST(stat_basic_test);
	RUN_TEST(stat_file_no_exist);
}

SUITE(fstat_test)
{
	RUN_TEST(fstat_file_test);
	RUN_TEST(fstat_badfile_test);
}

GREATEST_MAIN_DEFS();

int main(int argc, char **argv)
{
	GREATEST_MAIN_BEGIN();

	RUN_SUITE(stat_test);
	RUN_SUITE(fstat_test);

	GREATEST_MAIN_END();
	return (0);
}
