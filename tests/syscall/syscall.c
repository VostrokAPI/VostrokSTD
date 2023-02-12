#include <netinet/in.h>
#include <stdio.h>
#include "greatest.h"
#include "vs_syscall.h"
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <fcntl.h>

/////////////////////////////
//
//		SYSCALL TEST
//
/////////////////////////////

TEST		vs_syscall_getcwd(void)
{
	char	buf[2][0x100];

	getcwd(buf[0], sizeof(buf[0]));
	vs_syscall(VS_SYS_GETCWD, buf[1], sizeof(buf[1]));
	ASSERT_STR_EQ(buf[0], buf[1]);
	PASS();
}

TEST		vs_syscall_dup(void)
{
	int	fds[2] = {0, 0};

	fds[0] = dup(1);
	close(fds[0]);
	fds[1] = vs_syscall(VS_SYS_DUP, 0x1);
	close(fds[1]);
	ASSERT_EQ(fds[0], fds[1]);
	PASS();
}

TEST		vs_syscall_socket(void)
{
	int	fds[2] = {0, 0};

	fds[0] = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	close(fds[0]);
	fds[1] = vs_syscall(VS_SYS_SOCKET, AF_INET, SOCK_STREAM, IPPROTO_TCP);
	close(fds[1]);
	ASSERT_EQ(fds[0], fds[1]);
	PASS();
}

TEST		vs_syscall_write_read(void)
{
	char	buf[2][0x100];
	int		fds[2][2] = { {0, 0}, {0, 0}};
	int		status[2] = {0, 0};

	memset(buf[0], 0, sizeof(buf[0]));
	memset(buf[1], 0, sizeof(buf[1]));
	pipe(fds[0]);
	pipe(fds[1]);

	status[0] = write(fds[0][1], "hello world", 11);
	status[1] = vs_syscall(VS_SYS_WRITE, fds[1][1], "hello world", 11);

	close(fds[0][1]);
	close(fds[1][1]);

	ASSERT_EQ(status[0], status[1]);

	status[0] = read(fds[0][0], buf[0], sizeof(buf[0]));
	status[1] = vs_syscall(VS_SYS_READ, fds[1][0], buf[1], sizeof(buf[1]));

	close(fds[0][0]);
	close(fds[1][0]);

	ASSERT_EQ(status[0], status[1]);
	ASSERT_STR_EQ(buf[0], buf[1]);
	PASS();
}

TEST	vs_syscall_getpid(void)
{
	pid_t	pid[2] = {0, 0};

	pid[0] = getpid();
	pid[1] = vs_syscall(VS_SYS_GETPID);
	ASSERT_EQ(pid[0], pid[1]);
	PASS();
}

GREATEST_MAIN_DEFS();

SUITE(syscall_test)
{
	RUN_TEST(vs_syscall_getcwd);
	RUN_TEST(vs_syscall_dup);
	RUN_TEST(vs_syscall_socket);
	RUN_TEST(vs_syscall_write_read);
	RUN_TEST(vs_syscall_getpid);
}

int main(int argc, char **argv)
{
	GREATEST_MAIN_BEGIN();

	RUN_SUITE(syscall_test);

	GREATEST_MAIN_END();

	return (0);
}
